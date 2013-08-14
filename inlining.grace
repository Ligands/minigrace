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
def null = object {}
type Iterable = {
    iterator
}
type astNode = {
    kind
}
var placeRest := false
// wtf was i thinking here... code i cut that may still have a use
//.orElse{(values[v].kind == old.kind).andAlso{
//            values[v].kind == "identifier"}.andAlso{
//            (values[v].value == old.value)}}

// Performs a deep search in 'values' for 'old', and replaces it
// as well as parent nodes with new ast nodes.
method replaceVal(old)with(new)in(values){
    // print("looking to replace {old} with {new}...")
    for(1..values.size) do{ v ->
        if((values[v].kind != "callwithpart").andAlso{
            (values[v] == old)}) then {
            var vs := collections.list.new
            for(1..values.size) do { n ->
                if(n==v) then {
                    if (Iterable.match(new)) then {
                        if(new.size > 1) then {
                            vs.push(new.last)
                            placeRest := true;
                        } else {vs.push(new.first)}
                    } else {
                        if(new.kind == "identifier") then {
                            var temp := ast.identifierNode.new(new.value, new.dtype)
                            temp.register := new.register
                            temp.line := new.line
                            temp.linePos := new.linePos
                            vs.push(temp)
                        } else {vs.push(new)}
                    }
                } else {
                    vs.push(values[n])
                }
            }
            return [vs,v]
        } else {
            if(values[v].kind == "return") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.defDecNode.new(temp[1][1], values[v].value, values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.data := values[v].data
                    values[v] := t2
                    return [values, v]
                }
                temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.varDecNode.new(temp[1][1], values[v].value, values[v].dtype)
                    t2.annotations.extend(values[v].annotations)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
                if((values[v].value != null).andAlso{values[v].value != false} ) then {
                    temp := replaceVal(old)with(new)in([values[v].value])
                    if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.opNode.new(values[v].value,
                        temp[1][1], values[v].right)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in([values[v].right])
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
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
                    if(temp[1] != null) then {
                        t2 := ast.ifNode.new(values[v].value, temp[1], values[v].elseblock)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        t2.handledIdentifiers := values[v].handledIdentifiers
                        values[v] := t2
                        return [values,v]
                    }
                } else {
                    temp := replaceVal(old)with(new)in([values[v].thenblock])
                    if(temp[1] != null) then {
                        t2 := ast.ifNode.new(values[v].value, temp[1][1], values[v].elseblock)
                        t2.register := values[v].register
                        t2.line := values[v].line
                        t2.handledIdentifiers := values[v].handledIdentifiers
                        values[v] := t2
                        return [values,v]
                    }
                }
                temp := replaceVal(old)with(new)in(values[v].elseblock)
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.bindNode.new(temp[1][1], values[v].value)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                if(values[v].value != null) then {
                    temp := replaceVal(old)with(new)in([values[v].value])
                    if(temp[1] != null) then {
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
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.callNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if(values[v].kind == "member") then {
                var temp := replaceVal(old)with(new)in([values[v].in])
                if(temp[1] != null) then {
                    var t2 := ast.memberNode.new(values[v].value, temp[1][1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values, v]
                }
            }
            if(values[v].kind == "for") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != null) then {
                    var t2 := ast.forNode.new(temp[1][1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != null) then {
                    var t2 := ast.forNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "while") then {
                var temp := replaceVal(old)with(new)in([values[v].value])
                if(temp[1] != null) then {
                    var t2 := ast.whileNode.new(temp[1][1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != null) then {
                    var t2 := ast.whileNode.new(values[v].value, temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
            if(values[v].kind == "block") then {
                var temp := replaceVal(old)with(new)in(values[v].params)
                if(temp[1] != null) then {
                    var t2 := ast.blockNode.new(temp[1], values[v].body)
                    t2.register := values[v].register
                    t2.line := values[v].line
                    t2.matchingPattern := values[v].matchingPattern
                    values[v] := t2
                    return [values,v]
                }
                temp := replaceVal(old)with(new)in(values[v].body)
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    var t2 := ast.arrayNode.new(temp[1])
                    t2.register := values[v].register
                    t2.line := values[v].line
                    values[v] := t2
                    return [values,v]
                }
            }
        }
        // at this point, should be at base of the recursive stack.
        if(placeRest) then {
            for(1..(new.size-1)) do { n ->
                values.at(v)insert(n)
            }
            placeRest := false
        }
    }
    return [null, 0]
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

def recurCallVis = object {
    inherits ast.baseVisitor
    var root
    var recur
    method visitCall(o) -> Boolean {
        if(o.value.value == root.value.value) then{
            recur := true
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
    recurCallVis.recur
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
var identSet := null     // set of strings identifying unique identNodes
def identLocator = object {
    inherits ast.baseVisitor
    var allIdents := null    
    var constraint := null
    
    method visitIdentifier(o) -> Boolean {
        if(constraint == null) then {
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
    if(identSet == null) then { // initialize
        identLocator.constrain(null)
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

var propModified := false

method constFold(node){
    if(!astNode.match(node)) then { return false }
    //print("folding op: [{node.left}({node.left.value}) , {node.right}({node.right.value})]")
    if(node.kind == "op") then {
        var newNode := null
        // recursively fold each side of the opNode
        if(node.left.kind == "op") then {
            //print ("expanding left: [{node.left}({node.left.value})]")
            var tmp := constFold(node.left)
            if(tmp != false) then {
                newNode := ast.opNode.new(node.value, tmp, node.right)
                newNode.register := node.register
                newNode.line := node.line
            }
        }
        if(node.right.kind == "op") then {
            //print ("expanding right: [{node.right}({node.right.value})]")
            var tmp := constFold(node.right)

            if(tmp != false) then {
                if(newNode != null) then {
                    newNode := ast.opNode.new(node.value, newNode.left, tmp)
                } else { newNode := ast.opNode.new(node.value, node.left, tmp)}
                newNode.register := node.register
                newNode.line := node.line
            }
        }
        if(newNode == null) then {
            newNode := node }
        if((newNode.left.kind != newNode.right.kind).andAlso{
            (newNode.left.kind != "string") && (newNode.right.kind != "string")}) then {
            return false
        }
        if((newNode.left.kind == "num").andAlso{   // ** Number ** //
            newNode.right.kind == "num"}) then {
            if(newNode.value == "+") then {
                return ast.numNode.new((newNode.left.value.asNumber + newNode.right.value.asNumber).asString) }
            if(newNode.value == "-") then {
                return ast.numNode.new((newNode.left.value.asNumber - newNode.right.value.asNumber).asString) }
            if(newNode.value == "*") then {
                return ast.numNode.new((newNode.left.value.asNumber * newNode.right.value.asNumber).asString) }
            if(newNode.value == "/") then {
                return ast.numNode.new((newNode.left.value.asNumber / newNode.right.value.asNumber).asString) }
            if(newNode.value == "%") then {
                return ast.numNode.new((newNode.left.value.asNumber % newNode.right.value.asNumber).asString) }
            if(newNode.value == "^") then {
                return ast.numNode.new((newNode.left.value.asNumber ^ newNode.right.value.asNumber).asString) }
            if(newNode.value == ">") then {
                if(newNode.left.value.asNumber > newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
            if(newNode.value == ">=") then {
                if(newNode.left.value.asNumber >= newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
            if(newNode.value == "<") then {
                if(newNode.left.value.asNumber < newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
            if(newNode.value == "<=") then {
                if(newNode.left.value.asNumber <= newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
            if(newNode.value == "==") then {
                if(newNode.left.value.asNumber == newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
            if(newNode.value == "!=") then {
                if(newNode.left.value.asNumber != newNode.right.value.asNumber) then {
                    return ast.identifierNode.new("true", false) } else {
                    return ast.identifierNode.new("false", false) }
            }
                
            
            print("unhandled num op type: '{newNode.value}'")
            return false
        }
        if((newNode.left.kind == "identifier").andAlso{    // ** Boolean ** //
            newNode.right.kind == "identifier"}) then {
            if(((newNode.left.value == "true").orElse{newNode.left.value == "false"}).andAlso{
                (newNode.right.value == "true").orElse{newNode.right.value == "false"}}) then {
                var new := null
                if(newNode.value == "||") then {   // ** || (Or) ** //
                    if((newNode.left.value == "true") ||
                        (newNode.right.value == "true")) then {
                        new := ast.identifierNode.new("true", false)
                    }
                    elseif((newNode.left.value == "false") &&
                        (newNode.right.value == "false")) then {
                        new := ast.identifierNode.new("false", false)
                    } else {
                        new := "error"
                    }
                }
                if(newNode.value == "&&") then {   // ** && (And) ** //
                    if((newNode.left.value == "true") ||
                        (newNode.right.value == "true")) then {
                        new := ast.identifierNode.new("true", newNode.left.dtype)
                    }
                    elseif((newNode.left.value == "false") &&
                        (newNode.right.value == "false")) then {
                        new := ast.identifierNode.new("false", newNode.left.dtype)
                    } else {
                        new := "error"
                    }
                }
                
                
                if(new == null) then { return false }
                if(new == "error") then {
                    print("Boolean logic error: {newNode.left.value} {newNode.value} {newNode.right.value}")
                    return false
                }
                new.line := newNode.left.line
                new.linePos := newNode.left.linePos
                return new
            }
        }
        if(((newNode.left.kind == "string") || (newNode.left.kind == "num")).andAlso{    // ** String ** //
           (newNode.right.kind == "string") || (newNode.right.kind == "num")}) then {    // (or number- already string representation)
            if(newNode.value == "++") then {   // ** ++ (Concat) ** //
                return ast.stringNode.new(newNode.left.value ++ newNode.right.value) }
            
            print("unhandled string op type: '{node.value}'")
            return false
        }
        
        return newNode
    }
    false
}

def propVis = object {
    inherits ast.baseVisitor
    var idlist
    var idset
    var idsetFin
    
    method init(){
        idlist := collections.map.new
        idset := collections.set.new
        idsetFin := collections.set.new
    }
    
    method checkConst(o){
        return ((o.kind == "num") ||
            (o.kind == "string") ||
            ((o.kind == "identifier") &&
              ((o.value == "true") || (o.value == "false"))))
    }
    
    method newVar(o, name){
        if(o.value == false) then {
            return false
        }
        o.value.accept(self)
        if(idsetFin.contains(name)) then {    // ident has already been found twice
            return false
        }
        //print(" - looking in idset for {name}")
        if(idset.contains(name)) then {         // ident is already being searched, is found again
            //print("removing {name} in idset")
            idsetFin.add(name)
            idset.remove(name)
        } else {
            //print("checking const: {o.value}")
            if(checkConst(o.value)) then {      // begin searching for ident
                //print("adding {name} to idset")
                idset.add(name)
                var tmp := collections.list.new
                tmp.push(o.value)
                idlist.put(name, tmp)
            }
        }
        false   // prevent the dest/name part of nodes being changed
    }
    
    method visitIdentifier(o) -> Boolean {
        //print("looking for ident {o}[{o.value}]")
        if(idset.contains(o.value)) then {
            if(idlist.contains(o.value)) then {
                //print("adding {o}[{o.value}] to idlist")
                idlist.get(o.value).push(o)
            } else {
                print("Error: Shouldn't be getting here (method visitIdentifier() in propVis in inlining.grace) (o = {o}[{o.value}]")
            }
        }
        true
    }
    
    method visitDefDec(o) -> Boolean {
        return newVar(o, o.name.value)
    }
    
    var varFlag := false // set to false to prevent variables from propagating
    method visitBind(o) -> Boolean {
        if(!varFlag) then { return true }
        //print("(visitBind) {o}:{o.dest.value}")
        return newVar(o, o.dest.value)
    }
    
    method visitVarDec(o) -> Boolean {
        if(!varFlag) then { return true }
        //print("(visitVarDec) {o}:{o.name.value}")
        return newVar(o, o.name.value)
    }
}

def constFolder = object {
    inherits ast.baseVisitor
    var highLvlOps := collections.list.new
    
    method visitOp(o) -> Boolean {
        highLvlOps.push(o)
        return false
    }
}

def propBodyCollector = object {
    inherits ast.baseVisitor
    var bodies
    var bStack
    
    method init(){
        bodies := collections.list.new
        bStack := collections.list.new
    }
    method addToStack(i){
        bStack.push(i)
    }
    
    method visitBlock(o) -> Boolean {
        var l := collections.list.new
        addToStack(l)
        for(o.body) do { n ->
            n.accept(self)
            l.push(n)
            for(bStack) do { b ->
                if(b != l) then { b.push(n) }
            }
        }
        bodies.push(l)
        false
    }

    method visitMethod(o) -> Boolean {
        // if the method is an inl
        if(findAnnotation(o, "inline") && !recursiveCheck(o)) then {
        } else {
            visitBlock(o)
        }
        false
    }
    
    
    method visitClass(o) -> Boolean {
        var l := collections.list.new
        addToStack(l)
        for(o.value) do { n ->
            n.accept(self)
            l.push(n)
            for(bStack) do { b ->
                if(b != l) then { b.push(n) }
            }
        }
        bodies.push(l)
        false
    }
}

def ifCollector = object {
    inherits ast.baseVisitor
    var ifs
    
    method visitIf(o) -> Boolean {
        if((o.value.kind == "identifier").andAlso{  // if the if clause is a boolean literal, we can fold this ifNode.
            (o.value.value == "true") || (o.value.value == "false")}) then {
            ifs.push(o)
            false
        }
    }
}

method foldIf(node, lists) {
    var newIfs := collections.set.new
    for(lists) do { l ->
        var i := 1
        while{i <= l.size} do {
            if((l[i].kind == "if") && (node == l[i])) then {
                ifCollector.ifs := collections.list.new
                if(node.value.value == "true") then {
                    for(node.thenblock) do { in ->
                        in.accept(ifCollector)
                    }
                } else {
                    for(node.elseblock) do { in ->
                        in.accept(ifCollector)
                    }
                }
                for(ifCollector.ifs) do { in ->
                    newIfs.add(in)
                }
                l.delete(i)
                i := i - 1
            }
            i := i + 1
        }
    }
    newIfs
}
    
method constantProp(){
    // first, collect all of the bodies of syntactic scope levels to fold / propagate over
    propBodyCollector.init
    var l := collections.list.new
    propBodyCollector.addToStack(l)
    for(1..vals.size) do { in ->
        vals[in].accept(propBodyCollector)
        if(vals[in].kind == "method") then {
            if((!findAnnotation(vals[in], "inline")).orElse{recursiveCheck(vals[in])}) then {
                l.push(vals[in])
            }
        } else {
            l.push(vals[in])
        }
    }
    propBodyCollector.bodies.push(l)
    
    for(propBodyCollector.bodies) do { b -> // for each inlined method:
        //var inlBody := inlMethMap.get(i.pretty(0))
        
        propModified := true
        while{propModified} do {
            propModified := false
            
            // perform folding on all (highest-level) opNodes 
            constFolder.highLvlOps := collections.list.new
            for(1..b.size) do { in ->
                b[in].accept(constFolder)
            }
            for(1..constFolder.highLvlOps.size) do { o ->
                var op := constFolder.highLvlOps[o]
                var tmp := constFold(op)    // fold the opNode, if possible
                if((tmp != false) && (tmp != op)) then {
                    replaceVal(op)with(tmp)in(b)
                    replaceVal(op)with(tmp)in(vals)
                    propModified := true
                }
            }
            
            propVis.init()
            for(b) do { in ->
                in.accept(propVis)
            }
            
            // propagate the folded consts
            for(propVis.idlist) do { key ->
                var ar := propVis.idlist.get(key)
                var tmp := ar[1]
                //print ("ar.size = {ar.size}")
                //print("tmp = {tmp}[{tmp.value}]")
                for(2..ar.size) do { index ->
                    //print(" # replacing {tmp}[{tmp.value}] < {ar[index]}[{ar[index].value}]\n")
                    replaceVal(ar[index])with(tmp)in(b)
                    replaceVal(ar[index])with(tmp)in(vals)
                    if(!propModified) then { propModified := true }
                }
            }
            
            // fold conditionals
            var ifList := collections.list.new
            ifCollector.ifs := ifList
            for(b) do { in ->
                in.accept(ifCollector)
            }
            for(ifList) do { in ->
                //print("ifCollector: {in}[{in.value}({in.value.value})]")
                //print("b.pretty (before):")
                //for(b) do { i ->
                //    print(i.pretty(1))
                //}
                //print("")
                ifList.extend(foldIf(in, propBodyCollector.bodies))
                if(in.value.value == "true") then {
                    replaceVal(in)with(in.thenblock)in(vals)
                } else {
                    replaceVal(in)with(in.elseblock)in(vals)
                }
                //print("b.pretty (after):")
                //for(b) do { i ->
                //    print(i.pretty(1))
                //}
                //print("")
                //if(!propModified) then { propModified := true }
            }
            
        }   // end of propModified loop: should be no more propagation work to do at this point
        
        //inlMethMap.put(i.pretty(0), inlBody)
    }
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
        if(temp[1] != null) then {
            values[temp[2]] := temp[1][temp[2]]
        }// else {
            //print(" * mapping failed")
        //}
    }
    return values;
}

// creates a mapping of a call parameters to the method arguments
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

//locate a method declared as inline matching the given callnode name
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

def inlCallVis = object {
    inherits ast.baseVisitor
    method visitCall(o) -> Boolean {
        if(modified) then {
            return false
        }
        findMeth(o) //if call found, check if its to another inline meth
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
            while{modified} do {    //while more inlining to do
                modified := false
                //scan through EXTRA body looking for calls
                for(inlMethMap.get(i.pretty(0))) do { v ->
                    v.accept(inlCallVis)
                }
                if(modified) then {
                    var inlBody := inlMethMap.get(i.pretty(0))
                    var temp := replaceVal(replacee)with(replacer)in(inlBody)
                    if(temp[1] != null) then {
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
                if(temp[1] != null) then {
                    vals[temp[2]] := temp[1][temp[2]]
                } else {
                    print("replaceVal returned empty?")
                }
                c := c - 1
            }
            c := c + 1
        }
        // methods are inlined
        
        util.log_verbose "propagating constants."
        //constant folding
        constantProp()
    }
    
    
    
    return vals
}

