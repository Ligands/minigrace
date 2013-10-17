#pragma DefaultVisibility=public
method inline{}

method constantProp() is inline{
    def i : Number = 20
    return (i + 3)

}

method main(){
    def n = constantProp()
    if(n == 23) then {
        def n = 5
        if(n > 10) then {print("fail")}
        else {print("pass")}
    }
}

main()
