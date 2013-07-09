var orig := -1
method inline{}

method recurse(a) is inline {
    if(a < 1) then {
        orig := -1
        return true
    }
    if(orig < 0) then {
        orig := a
    }
    print ("recurse {orig-a+1}")
    recurse(a-1)
}

method call() is inline {
    print("call")
}

method main(){
    call
    recurse(5)
}

main()
