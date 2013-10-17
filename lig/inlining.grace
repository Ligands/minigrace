#pragma DefaultVisibility=public
// minigrace inlining module.
// author: luke bravenboer
// year: 2013

import "ast" as ast
import "mgcollections" as collections
import "io" as io
import "util" as util

var modified := false
var replacer := ""
var replacee := ""
var vals := []
var inls := collections.list.new
var inlMethMap := collections.map.new
var inliningCalls := false

// ------------------------------------------------------------ //
// ----------------  AST Node Replacer Methods  --------------- //
// ------------------------------------------------------------ //

type Iterable = {
    iterator
}
type astNode = {
    kind
}
var placeRest := false;

// Performs a deep search in 'values' for 'old', and replaces it
// as well as parent nodes with new ast nodes.
method replaceVal(old)with(new)in(values){
    for(1..values.size) do{ v ->
        //print(values[v].kind)
        if((values[v].kind != "callwithpart").andAlso{
            (values[v] == old).orElse{
            (values[v].kind == old.kind) &&
            (values[v].value == old.value)}}) then {
            var vs := collections.list.new
            for(1..values.size) do { n ->
                if(n==v) then {
                    if (Iterable.match(new)) then {
                        vs.push(new.last)
                        placeRest := true;
                    } else {
                        if(new.kind == "identifier") then {
                            var temp := ast.identifierNode.new(new.value, new.dtype)
                            temp.register := new.register
                            temp.line := new.line
                            temp.linePos := new.linePos
                            vs.push(temp)
                        } else {
                            vs.push(new)
                        }
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
                var temp := replaceVal(old)with(new)in([values[v].name])
                if(temp[1] != nothing) then {
                    var t2 := ast.defDecNode.new(temp[1][1], values[v].value, values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.data := values[v].data
                    values[v] := t2
                    return [values, v]
                }
                temp := replaceVal(old)with(new)in([values[v].value])
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
            if(values[v].kind == "vardec") then {
                var temp := replaceVal(old)with(new)in([values[v].name])
                if(temp[1] != nothing) then {
                    var t2 := ast.varDecNode.new(temp[1][1], values[v].value, values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
                if((values[v].value != nothing).andAlso{values[v].value != false} ) then {
                    temp := replaceVal(old)with(new)in([values[v].value])
                    if(temp[1] != nothing) then {
                        var t2 := ast.varDecNode.new(values[v].name, temp[1][1], values[v].dtype)
                        t2.annotations.extend(values[v].annotations)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        values[v] := t2
                        return [values, v]
                    }
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
                //print("[if]")
                var temp := replaceVal(old)with(new)in([values[v].value])
                var t2
                if(temp[1] != nothing) then {
                    t2 := ast.ifNode.new(temp[1][1],
                        values[v].thenblock, values[v].elseblock)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.handledIdentifiers := values[v].handledIdentifiers
                    values[v] := t2
                    return [values,v]
                }
                if(Iterable.match(values[v].thenblock)) then {
                    var tAr := 1..values[v].thenblock.size
                    for(1..tAr.size) do { n ->
                        tAr[n] := values[v].thenblock[n]
                    }
                    temp := replaceVal(old)with(new)in(tAr)
                    if(temp[1] != nothing) then {
                        t2 := ast.ifNode.new(values[v].value, temp[1], values[v].elseblock)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        t2.handledIdentifiers := values[v].handledIdentifiers
                        values[v] := t2
                        return [values,v]
                    }
                } else {
                    temp := replaceVal(old)with(new)in([values[v].thenblock])
                    if(temp[1] != nothing) then {
                        t2 := ast.ifNode.new(values[v].value, temp[1][1], values[v].elseblock)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        t2.handledIdentifiers := values[v].handledIdentifiers
                        values[v] := t2
                        return [values,v]
                    }
                }
                temp := replaceVal(old)with(new)in(values[v].elseblock)
                if(temp[1] != nothing) then {
                    t2 := ast.ifNode.new(values[v].value,
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
                if(values[v].value != nothing) then {
                    temp := replaceVal(old)with(new)in([values[v].value])
                    if(temp[1] != nothing) then {
                        var t2 := ast.bindNode.new(values[v].dest, temp[1][1])
                        t2.register := values[v].register
                        t2.line := values[v].line
                        values[v] := t2
                        return [values,v]
                    }
                }
            }
            if(values[v].kind == "callwithpart") then {
                var tAr := 1..values[v].args.size
                for(1..tAr.size) do { n ->
                    tAr[n] := values[v].args[n]
                }
                var temp := replaceVal(old)with(new)in(tAr)
                if(temp[1] != nothing) then {
                    var t2 := ast.callWithPart.new(values[v].name, temp[1])  // *** 
                    t2.name := values[v].name
                    values[v] := t2
                    return [values, v]
                }
            }
            if(values[v].kind == "call") then {
                var tAr := 1..values[v].with.size
                for(1..tAr.size) do { n ->
                    tAr[n] := values[v].with[n]
                }
                var temp := replaceVal(old)with(new)in(tAr)
                if(temp[1] != nothing) then {
                    var t2 := ast.callNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
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
                        var tempRest := collections.list.new
                        for(1..temp[1].size) do { t ->
                            if(t == temp[2]) then {
                                for(new) do { n ->
                                    tempRest.push(n)
                                }
                                tempRest.pop
                            }
                            tempRest.push(temp[1][t])
                        }
                        placeRest := false
                        // to primitive array
                        temp[1] := 1..(tempRest.size)
                        for(1..tempRest.size) do { t ->
                            temp[1][t] := tempRest[t]
                        }
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
                    if(placeRest) then {
                        var tempRest := collections.list.new
                        for(1..temp[1].size) do { t ->
                            if(t == temp[2]) then {
                                for(new) do { n ->
                                    tempRest.push(n)
                                }
                                tempRest.pop
                            }
                            tempRest.push(temp[1][t])
                        }
                        placeRest := false
                        // to primitive array
                        temp[1] := 1..(tempRest.size)
                        for(1..tempRest.size) do { t ->
                            temp[1][t] := tempRest[t]
                        }
                    }
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
                    if(placeRest) then {
                        var tempRest := collections.list.new
                        for(1..temp[1].size) do { t ->
                            if(t == temp[2]) then {
                                for(new) do { n ->
                                    tempRest.push(n)
                                }
                                tempRest.pop
                            }
                            tempRest.push(temp[1][t])
                        }
                        placeRest := false
                        // to primitive array
                        temp[1] := 1..(tempRest.size)
                        for(1..tempRest.size) do { t ->
                            temp[1][t] := tempRest[t]
                        }
                    }
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
            if(values[v].kind == "array") then {
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

// ------------------------------------------------------------ //
// ---------------------  Helper Methods  --------------------- //
// ------------------------------------------------------------ //

method findAnnotation(node, annName) {
    for (node.annotations) do {ann->
        if (ann.value.value == annName) then {
            return true
        }
    }
    false
}

// ------------------------------------------------------------ //
// ----------------  VarDec Name Clash Methods  --------------- //
// ------------------------------------------------------------ //

def varDecLocator = object {
    inherits ast.baseVisitor
    var list
    method visitVarDec(o) -> Boolean {
        list.push(o)
        true
    }
}
var identSet := nothing     // set of strings identifying unique identNodes
def identLocator = object {
    inherits ast.baseVisitor
    var allIdents := nothing    
    var constraint := nothing
    
    method visitIdentifier(o) -> Boolean {
        if(constraint == nothing) then {
            identSet.add(o.value)
            return true
        } else {
            if(o.value == constraint) then {
                //print ("{o} : {o.value} == {constraint}")
                allIdents.push(o)
                return true
            }
        }
    }
    
    method constrain(c){
        constraint := c
    }
}
var uid := 0
// creates a new, unique identifier
method generateIdentifier(){
    if(identSet == nothing) then { // initialize
        identLocator.constrain(nothing)
        identSet := collections.set.new
        for(vals) do { v ->
            v.accept(identLocator)
        }
    }
    var name := "inlinedVar_{uid}"
    uid := uid + 1
    while{identSet.contains(name)} do {
        name := "inlinedVar_{uid}"
        uid := uid + 1
    }
    name
}

method fixConflicts(){  // give all inlined variables unique identifiers
    for(inls) do { i -> // for each inlined method:
        var inlBody := inlMethMap.get(i.pretty(0))
        varDecLocator.list := collections.list.new
        for(inlBody) do { in ->
            in.accept(varDecLocator)
        }
        for(varDecLocator.list) do { vd ->   // for each varDec in inlined method:
            var newID := generateIdentifier()
            identLocator.allIdents := collections.list.new
            identLocator.constrain(vd.name.value)
            for(inlBody) do { in ->
                in.accept(identLocator)
            }
            
            for(identLocator.allIdents) do { id ->
                replaceVal(id)with(ast.identifierNode.new(newID, false))in(inlBody)
            }
        }
        inlMethMap.put(i.pretty(0), inlBody)
    }
}

// ------------------------------------------------------------ //
// ----------------- Constant Prop. Methods  ------------------ //
// ------------------------------------------------------------ //

method constFold(node){
    if(!astNode.match(node)) then { return false }
    if(node.kind == "op") then {
        // recursively fold each side of the opNode
        if(node.left.kind == "op") then {
            var tmp := constFold(node.left)
            if(tmp == false) then { return false }
            node.left := tmp
        }
        if(node.right.kind == "op") then {
            var tmp := constFold(node.right)
            if(tmp == false) then { return false }
            node.right := tmp
        }
        if((node.left.kind == "num").andAlso{
            node.right.kind == "num"}) then {
            if(node.value == "+") then {
                return ast.numNode.new(node.left.value + node.right.value) }
            if(node.value == "-") then {
                return ast.numNode.new(node.left.value - node.right.value) }
            if(node.value == "*") then {
                return ast.numNode.new(node.left.value * node.right.value) }
            if(node.value == "/") then {
                return ast.numNode.new(node.left.value / node.right.value) }
            print("unhandled num op type: '{node.value}'")
            return false
        }
        if(node.value == "||") then {
            if((node.left.kind == "identifier").andAlso{
                node.right.kind == "identifier"}) then {
                var new := nothing
                // if both nodes are boolean and 'or' together true
                if(((node.left.value == "true").andAlso{
                    (node.right.value == "false") || (node.right.value == "true")} ||
                    (node.right.value == "true").andAlso{
                    (node.right.value == "false") || (node.right.value == "true")}) then {
                    new := ast.identifierNode.new("true", node.left.dtype)
                }
                if((node.left.value == "false") &&
                    (node.right.value == "false")) then {
                    new := ast.identifierNode.new("false", node.left.dtype)
                }
                if(new == nothing) then { return false }
                new.line := node.left.line
                new.linePos := node.left.linePos
                return new
            }
        }
        if(node.value == "&&") then {
        
        }
        
        
        
        return true
    }
    false
}

method constantProp(){
    
    
    
}

// ------------------------------------------------------------ //
// -------------------- Inlining Methods  --------------------- //
// ------------------------------------------------------------ //

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
            replacer := inlBody //.last
            modified := true
        }
        if(modified) then {
            return
        }
    }
}

def recurCallVis = object {
    inherits ast.baseVisitor
    
    var root
    var recur
    method visitCall(o) -> Boolean {
        //print("(recur:) {o}({o.value.value}) : {root}({root.value.value})")
        if(o.value.value == root.value.value) then{
            recur := true
            //print("recursion!")
        }
        true
    }
    method setRoot(o) {
        root := o
        recur := false
    }
}

method recursiveCheck(meth){
    recurCallVis.setRoot(meth)
    meth.accept(recurCallVis)
    return recurCallVis.recur
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
    util.log_verbose "inlining method calls."
    vals := collections.list.new
    vals.extend(values)
    var n := 1
    var bod
    // map inline methods to additional inlined body
    for(vals) do { v ->
        if((v.kind == "method").andAlso{
            findAnnotation(v, "inline")}) then {
            //check first for recursion
            if(!recursiveCheck(v)) then {
                inls.push(v)
                bod := collections.list.new
                bod.extend(v.body)
                inlMethMap.put(v.pretty(0), bod)
            }
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
        
        // rename inlined variable declarations with naming conflicts
        fixConflicts()
        
        //print("inlining method bodies complete. replacing inline calls...")
        inliningCalls := true
        // evaluate all calls to inline methods
        var c := 1
        while{c <= vals.size} do {
            modified := false
            //print(vals[c])
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
    }   // methods are inlined
    
    util.log_verbose "propagating constants."
    //constant folding
    constantProp()
    
    return vals
}

