#pragma DefaultVisibility=public
import "ast" as ast
import "mgcollections" as collections
import "io" as io
import "util" as util

var modified := false
var caller := ""
var oldCall := ""
var vals := []

method replaceVal(values){
    //print("{values}: {oldCall}")
    for(1..values.size) do{ v ->
        //print("comparing {values[v]}({values[v].kind}) to {oldCall}")
        if(values[v] == oldCall) then {
            values[v] := caller
            return [values,v]
        } else {
            if(values[v].kind == "return") then {
                var temp := replaceVal([values[v].value])
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
                var temp := replaceVal([values[v].value])
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
                var temp := replaceVal([values[v].value])
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
                var temp := replaceVal([values[v].left])
                if(temp[1] != nothing) then {
                    var t2 := ast.opNode.new(values[v].value,
                        temp[1][1], values[v].right)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal([values[v].right])
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
                var temp := replaceVal([values[v].thenblock])
                if(temp[1] != nothing) then {
                    var t2 := ast.ifNode.new(values[v].value,
                        temp[1][1], values[v].elseblock)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.handledIdentifiers := values[v].handledIdentifiers
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal([values[v].elseblock])
                if(temp[1] != nothing) then {
                    var t2 := ast.ifNode.new(values[v].value,
                        values[v].thenblock, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "bind") then {
                var temp := replaceVal([values[v].dest])
                if(temp[1] != nothing) then {
                    var t2 := ast.bindNode.new(temp[1][1], values[v].value)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal([values[v].value])
                if(temp[1] != nothing) then {
                    var t2 := ast.bindNode.new(values[v].dest, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "call") then {
                print(" + callparts = {values[v].with}")
                for(1..values[v].with) do { w ->
                    var temp := replaceVal(old)with(new)in(values.with[w].args)
                    if(temp[1] != nothing) then {
                        var t3 := ast.callWithPart.new([values.with[w].name, temp[1]])
                        var t4 := []
                        for(1..values.with.size) do { n ->
                            if(w == n) then {
                                t4.push(t3)
                            } else {
                                t4.push(values.with[n])
                            }
                        }
                        var t2 := ast.callNode.new(values[v].value, t4)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        values[v] := t2
                        return [values,v]
                    }
                }
            }
            if(values[v].kind == "callwithpart") then {
                var temp := replaceVal(values[v].args)
                if(temp[1] != nothing) then {
                    values[v].args[temp[2]] := temp[1][temp[2]]
                    return [values, v]
                }
            }
            if(values[v].kind == "member") then {
                var temp := replaceVal([values[v].in])
                if(temp[1] != nothing) then {
                    var t2 := ast.memberNode.new(values[v].value, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if((values[v].kind == "class").orElse{
                values[v].kind == "object"}.orElse{
                values[v].kind == "array"}) then {
                var temp := replaceVal(values[v].value)
                if(temp[1] != nothing) then {
                    values[v].value[temp[2]] := temp[1][temp[2]]
                    return [values, v]
                }
            }
            if((values[v].kind == "for").orElse{
                values[v].kind == "while"}.orElse{
                values[v].kind == "block"}.orElse{
                values[v].kind == "method"}) then {
                var temp := replaceVal(values[v].body)
                if(temp[1] != nothing) then {
                    values[v].body[temp[2]] := temp[1][temp[2]]
                    return [values, v]
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
method setArgMap(m){
    argMap := m
    identList := collections.list.new
}

method processIdents(values){
    var oldcaller := caller
    var oldoldCall := oldCall
    for(identList) do { i ->
        caller := argMap.get(i.pretty(0))
        oldCall := i
        var temp := replaceVal(values)
        print("mapping: <{caller}({caller.value}) -> {oldCall}({oldCall.value})>")
        if(temp[1] != nothing) then {
            values[temp[2]] := temp[1][temp[2]]
            print("mapped. ({values[temp[2]].pretty(0)})")
        } else {
            print(" * mapping failed")
        }
    }
    caller := oldcaller
    oldCall := oldoldCall
    return values;
}

def methVis = object {
    inherits ast.baseVisitor
    method visitMethod(o) -> Boolean {
        if(modified) then {
            return true
        }
        if((o.value.value == caller.value.value).andAlso {
            findAnnotation(o,"inline")}) then {
            print("in: {o}({o.value.value}), {caller}({caller.value.value})")
            // *** This is where inlining happens. ***
            var temp := o.bodyInl
            //form the argument map
            var m := collections.map.new
            var l := collections.list.new
            for(caller.with) do { part ->
                for (part.args) do { arg ->
                    l.push(arg)
                }
            }
            var i := 1
            for (o.signature) do { part ->
                for (part.params) do { p ->
                    print("map entry: <{p.pretty(0)}, {l.at(i)}>")
                    m.put(p.pretty(0), l.at(i))
                    i := i+1
                }
            }
            setArgMap(m)
            for(temp) do{ t ->
                t.accept(identVis)
            }
            print("caller = {caller.pretty(0)}")
            print("evaluating: {temp[1].pretty(0)}")
            var s := ""
            for(l)do{n->
                s := "{s}{n.value}, "
            }
            print("caller idents=[{s}]")
            temp := processIdents(temp)
            print("evaluated: {temp[1].pretty(0)}")
            
            if(temp.last.kind == "return") then {
                temp[temp.size] := temp.last.value
            }
            //print("out: {temp.last}({temp.last.value}) -> {caller}({caller.value})")
            caller := temp.last
            modified := true
        }
        true
    }
}

method findMeth(o) {
    //print("looking for method '{o.value.value}'")
    for (vals) do { v ->
        caller := o
        v.accept(methVis)
        if(modified) then {
            return
        }
    }
}

def callVis = object {
    inherits ast.baseVisitor
    var inlMethInner := false   // used to match a callVis
    method visitCall(o) -> Boolean {
        if(modified) then {
            return true
        }
        //print("> investigating call node {o.pretty(0)}")
        findMeth(o)
        oldCall := o
        //print("> post-investigation of node {o.pretty(0)}")
        true
    }
}

method printTree(values){
    print("*****")
    for(vals) do { v ->
        if((v.kind == "class").andAlso{v.name.value == "conc"}) then {
            print(v.pretty(0))
        }
    }
    print("*****")
}

// Begins the inlining process on the ast.
method process(values) {
    vals := values
    var n := 1
    while{n <= vals.size} do {
        vals[n].accept(callVis)
        if(modified) then {
            var temp := replaceVal(vals)
            //print("replaced: <{caller} -> {oldCall}>")
            if(temp[1] != nothing) then {
                vals[temp[2]] := temp[1][temp[2]]
                //print("> post-investigation of node {caller.pretty(0)}")
            } else {
                //print("replaceVal returned empty?")
            }
            modified := false
            n := n - 1
            //print("press enter to view tree")
            //printTree(vals)
            print("press enter to continue")
            io.input.getline
        }
        n := n + 1
    }
    return vals
}

