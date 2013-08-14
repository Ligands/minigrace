#pragma DefaultVisibility=public
method inline{}

method varProp() is inline{
    var i : Number := 20
    print ("the answer is {i + 3}")
}

method main(){
    varProp()
}

main()
