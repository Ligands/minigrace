#pragma DefaultVisibility=public
import "ast" as ast
import "mgcollections" as collections
import "io" as io

var modified := false
var replacer := ""
var replacee := ""
var vals := []
var inls := collections.list.new
var inlMethMap := collections.map.new
var inliningCalls := false

type Iterable = {
    iterator
}

var placeRest := false;

// Performs a deep search in 'values' for 'old', and replaces it
// as well as parent nodes with new ast nodes.
method replaceVal(old)with(new)in(values){
    for(1..values.size) do{ v ->
        if((values[v] == old) ||
            ((values[v].kind == old.kind) &&
            (values[v].value == old.value))) then {
            var vs := collections.list.new
            for(1..values.size) do { n ->
                if(n==v) then {
                    if (Iterable.match(new)) then {
                        vs.push(new.last)
                        placeRest := true;
                    } else {
                        vs.push(new)
                    }
                } else {
                    vs.push(values[n])
                }
            }
            return [vs,v]
        } else {
            if(values[v].kind == "return") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.returnNode.new(temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if((values[v].kind == "defdec").andAlso{
                values[v].value != false}) then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.defDecNode.new(values[v].name, temp[1][1], values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.data := values[v].data
                    values[v] := t2
                    return [values, v]
                }
            }
            if((values[v].kind == "vardec").andAlso{
                values[v].value != false}) then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.varDecNode.new(values[v].name, temp[1][1], values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if(values[v].kind == "op") then {
                var temp := replaceVal(old)with(new)in([values[v].left])
                if(temp[1] != nothing) then {
                    var t2 := ast.opNode.new(values[v].value,
                        temp[1][1], values[v].right)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in([values[v].right])
                if(temp[1] != nothing) then {
                    var t2 := ast.opNode.new(values[v].value,
                        values[v].left, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "if") then {
                var temp := replaceVal(old)with(new)in([values[v].thenblock])
                if(temp[1] != nothing) then {
                    var t2 := ast.ifNode.new(values[v].value,
                        temp[1][1], values[v].elseblock)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.handledIdentifiers := values[v].handledIdentifiers
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in([values[v].elseblock])
                if(temp[1] != nothing) then {
                    var t2 := ast.ifNode.new(values[v].value,
                        values[v].thenblock, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.handledIdentifiers := values[v].handledIdentifiers
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "bind") then {
                var temp := replaceVal(old)with(new)in([values[v].dest])
                if(temp[1] != nothing) then {
                    var t2 := ast.bindNode.new(temp[1][1], values[v].value)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.bindNode.new(values[v].dest, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "call") then {
                for(1..values[v].with.size) do { n ->
                    var temp := replaceVal(old)with(new)in(values[v].with[n].args)
                    if(temp[1] != nothing) then {
                        var t3 := 1..values[v].with.size
                        for (1..t3.size) do {i->
                            t3[i] := (values[v].with[i])
                        }
                        t3[n] := ast.callWithPart.new(values[v].with[n].name, temp[1])
                        var t2 := ast.callNode.new(values[v].value, t3)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        values[v] := t2
                        return [values, v]
                    }
                }
            }
            if(values[v].kind == "member") then {
                var temp := replaceVal(old)with(new)in([values[v].in])
                if(temp[1] != nothing) then {
                    var t2 := ast.memberNode.new(values[v].value, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if(values[v].kind == "for") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.forNode.new(temp[1][1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != nothing) then {
                    var t2 := ast.forNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "while") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.whileNode.new(temp[1][1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != nothing) then {
                    var t2 := ast.whileNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "block") then {
                var temp := replaceVal(old)with(new)in(values[v].params)
                if(temp[1] != nothing) then {
                    var t2 := ast.blockNode.new(temp[1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.matchingPattern := values[v].matchingPattern
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != nothing) then {
                    if(placeRest) then {
                        var t3 := collections.list.new
                        for(1..temp[1].size) do { t ->
                            if(t == temp[2]) then {
                                for(new) do { n ->
                                    t3.push(n)
                                }
                                t3.pop
                            }
                            t3.push(temp[1][t])
                        }
                        placeRest := false
                        // to primitive array
                        var t4 := 0..(t3.size-1)
                        var tc := 1
                        for(t3) do { t ->
                            t4[tc] := t
                            tc := tc + 1
                        }
                        temp[1] := t4
                    }
                    var t2 := ast.blockNode.new(values[v].params, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.matchingPattern := values[v].matchingPattern
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "method") then {
                var temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != nothing) then {
                    var t2 := ast.methodNode.new(values[v].value,
                        values[v].signature, temp[1], values[v].dtype)
                    t2.varargs := values[v].varargs
                    t2.generics := values[v].generics
                    t2.selfclosure := values[v].selfclosure
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "class") then {
                var temp := replaceVal(old)with(new)in(values[v].value)
                if(temp[1] != nothing) then {
                    var t2 := ast.classNode.new(values[v].name,
                        values[v].signature, temp[1], values[v].superclass,
                        values[v].constructor)
                    t2.generics := values[v].generics
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.instanceMethods := values[v].instanceMethods
                    t2.data := values[v].data
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "object") then {
                var temp := replaceVal(old)with(new)in(values[v].value)
                if(temp[1] != nothing) then {
                    var t2 := ast.objectNode.new(temp[1], values[v].superclass)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.otype := values[v].otype
                    t2.classname := values[v].classname
                    t2.data := values[v].data
                    values[v] := t2
                    return [values,v]
                }
            }
            if((values[v].kind == "array") then {
                var temp := replaceVal(old)with(new)in(values[v].value)
                if(temp[1] != nothing) then {
                    var t2 := ast.arrayNode.new(temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
        }
    }
    return [nothing, 0]
}

method findAnnotation(node, annName) {
    for (node.annotations) do {ann->
        if (ann.value.value == annName) then {
            return true
        }
    }
    false
}

var argMap := []
var identList := []
def identVis = object {
    inherits ast.baseVisitor
    method visitIdentifier(o) -> Boolean {
        if(argMap.contains(o.pretty(0))) then {
            identList.push(o)
        }
        true
    }
}

// converts all identifiers in the given list (values) using the argMap and identList.
method processIdents(values){
    identList := collections.list.new
    // find all identifiers that require converting
    for(values) do{ t ->
        t.accept(identVis)
    }
    
    for(identList) do { i ->
        var temp := replaceVal(i)with(argMap.get(i.pretty(0)))in(values)
        //print("mapping: <{argMap.get(i.pretty(0))}({argMap.get(i.pretty(0)).value}) -> {i}({i.value})>")
        if(temp[1] != nothing) then {
            values[temp[2]] := temp[1][temp[2]]
            //print("mapped. ({values[temp[2]]})")
        }// else {
            //print(" * mapping failed")
        //}
    }
    return values;
}

// creates a mapping of a call's parameters to the method's arguments
method setArgMap(call, meth){
    var m := collections.map.new
    var l := collections.list.new
    for(call.with) do { part ->
        for (part.args) do { arg ->
            l.push(arg)
        }
    }
    var n := 1
    for (meth.signature) do { part ->
        for (part.params) do { p ->
            m.put(p.pretty(0), l.at(n))
            n := n+1
        }
    }
    argMap := m
}

//locate a method declared as inline matching the given callnode's name
method findMeth(o) {
    //print("looking for inline-annotated method '{o.value.value}'")
    for (inls) do { i ->
        if(i.value.value == o.value.value) then {
            var inlBody := collections.list.new
            //print("call to replace: {o.pretty(0)}")
            //print("pre-modification: {i.pretty(0)}")
            inlBody.extend(i.body)
            
            //form the argument map
            setArgMap(o, i)
            
            // convert idents using argmap
            inlBody := processIdents(inlBody)
            if(inlBody.last.kind == "return") then {
                inlBody[inlBody.size] := inlBody.last.value
            }
            //print("post-mod normalBody: {i.pretty(0)}")
            //inlMethMap.put(i.pretty(0), inlBody)
            replacer := inlBody.last
            modified := true
        }
        if(modified) then {
            return
        }
    }
}

def inlCallVis = object {
    inherits ast.baseVisitor
    method visitCall(o) -> Boolean {
        if(modified) then {
            return false
        }
        findMeth(o) //if call found, check if it's to another inline meth
        replacee := o
        true
    }
}

def callVis2 = object {
    inherits ast.baseVisitor
    method visitCall(o) -> Boolean {
        if(modified) then {
            return false
        }
        for(inls) do { i->
            //print("{o}({o.value.value}) : {i.value}({i.value.value})")
            if(o.value.value == i.value.value) then {
                replacee := o
                replacer := i
                modified := true
                return true
            }
        }
        true
    }
    method visitMethod(o) -> Boolean {
        for(inls) do { i->
            if(o == i) then {
                return false
            }
        }
        true
    }
}

// Begins the inlining process on the ast.
method process(values) {
    vals := collections.list.new
    vals.extend(values)
    var n := 1
    var bod
    // map inline methods to additional inlined body
    for(vals) do { v ->
        if((v.kind == "method").andAlso{
            findAnnotation(v, "inline")}) then {
            inls.push(v)
            bod := collections.list.new
            bod.extend(v.body)
            inlMethMap.put(v.pretty(0), bod)
        }
    }
    if(inls.size > 0) then {
        // inline the extra body part of inline methods
        //print("inlining methods...")
        for(inls) do{ i ->
            modified := true
            while{modified} do {    //while there's more inlining to do
                modified := false
                //scan through EXTRA body looking for calls
                for(inlMethMap.get(i.pretty(0))) do { v ->
                    v.accept(inlCallVis)
                }
                if(modified) then {
                    var inlBody := inlMethMap.get(i.pretty(0))
                    var temp := replaceVal(replacee)with(replacer)in(inlBody)
                    if(temp[1] != nothing) then {
                        inlBody[temp[2]] := temp[1][temp[2]]
                    }
                }
            }
        }
        
        //print("inlining method bodies complete. replacing inline calls...")
        inliningCalls := true
        // evaluate all calls to inline methods
        var c := 1
        while{c <= vals.size} do {
            modified := false
            print(vals[c])
            vals[c].accept(callVis2)
            if(modified) then {
                //form the argument map
                setArgMap(replacee, replacer)
                
                var temp := collections.list.new
                temp.extend(inlMethMap.get(replacer.pretty(0)))
                replacer := temp
                
                // convert idents using argmap
                replacer := processIdents(replacer)
                
                if(replacer.last.kind == "return") then {
                    replacer.at(replacer.size)put(replacer.last.value)
                }
                
                temp := replaceVal(replacee)with(replacer)in(vals)
                if(temp[1] != nothing) then {
                    vals[temp[2]] := temp[1][temp[2]]
                } else {
                    print("replaceVal returned empty?")
                }
                c := c - 1
            }
            c := c + 1
        }
    }
    return vals
}

