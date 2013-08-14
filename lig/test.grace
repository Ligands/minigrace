#pragma DefaultVisibility=public
var orig := -1
method inline{}

method namingConflict() is inline{
    var foo := "name conflicts okay 1"
    print(foo)
}

var recur := 0
method recurse(a) is inline {
    if(a < 1) then {
        orig := -1
        return true
    }
    if(orig < 0) then {
        orig := a
    }
    recur := recur + ((orig-a)+1)
    recurse(a-1)
}

method constantProp2(a) is inline {
    var b := a - 2
    return (b + 7)
}

method constantProp1() is inline{
    var a := 29 + 1
    var b := 9 - (a / 5);
    var c 
    c := b * 4
    var d := true || false
    d := true.orElse{false}
    if(c > 10) then{
        c := c - 10
    }
    return c * (60 / a)
}

method multiLine() is inline {
    var a := 1
    var b := 2
    if((a+b) == 3) then {
        print("multi-line okay")
    } else {
        print("multi-line FAIL")
    }
}

method main(){
    recurse(4)
    if(recur == 10) then {
        print("recursive okay")
    } else {
        print("recursive FAIL")
    }
    
    multiLine
    
    var foo := "name conflicts okay 2"
    namingConflict
    print(foo)
    
    constantProp1()
    
    var a := 5
    var b := constantProp2(a+3)
    if(b == 13) then {
        print("constantProp_Test")
    } else {
        print("constantProp_Test FAIL")
    }
}

main()
