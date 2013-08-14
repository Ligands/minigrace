#pragma DefaultVisibility=public
method inline{}

method constantProp() is inline{
    def i : Number = 20
    print ("the answer is {i + 3}")
}

method main(){
    constantProp()
}

main()
