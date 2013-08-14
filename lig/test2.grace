#pragma DefaultVisibility=public
method inline{}

method constantProp1() is inline{
    var a := 29 + 1
    print(a)
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

method main(){
    print("the answer is {constantProp1()}")
}

main()
