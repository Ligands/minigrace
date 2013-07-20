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
}

main()
