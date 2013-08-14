method show(u, w, h){
    var s;
    //display array contents
    for(0..(h-1)) do{y->
        s := "";
        for(0..(w-1)) do{x->
            if(u[y][x] == 0) then {
                s := "{s}.";
            } else {
                s := "{s}#";
            }
        }
        print (s);
    }
}

method evolve(u, w, h){
    var new := PrimitiveArray.new(h);
    for(0..(h-1))do{i->
        new[i] := PrimitiveArray.new(w);
        for(0..(w-1))do{j->
            new[i][j] := 0;
        }
    }
    for(0..(h-1)) do{y->
        for(0..(w-1)) do{x->
            var n := 0;
            for((y-1)..(y+1)) do{y1->
                for((x-1)..(x+1)) do{x1->
                    if(u[(y1+h)%h][(x1+w)%w] == 1) then{
                        n := n+1;
                    }
                }
            }
            if(u[y][x] == 1) then{
                n := n-1;
            }
            if((n == 3) || ((n == 2) && (u[y][x] == 1))) then{
                new[y][x] := 1;
            }
        }
    }
    for(0..(h-1)) do{y->
        for(0..(w-1)) do{x->
            u[y][x] := new[y][x];
        }
    }
}

method game(univ, w, h, num){
    //main loop
    print ("------");
    for(1..num) do {i->
        print ("Generation {i}:");
        show(univ, w, h);
        evolve(univ, w, h);
        print ("------");
        //wait(300);
    }
}

method wait(n){
    var o := 0
    for(0..n) do{i->
        for(0..350) do{x->
            o := x
        }
    }
}

method construct(w, h){
    var univ := PrimitiveArray.new(h);
    for(0..(h-1))do{i->
        //print (i)
        univ[i] := PrimitiveArray.new(w);
        for(0..(w-1))do{j->
            univ[i][j] := 0;
        }
    }
    return univ;
}

method block(){
    var univ := construct(4,4)
    
    univ[2][2] := 1;
    univ[2][3] := 1;
    univ[3][2] := 1;
    univ[3][3] := 1;
    
    print ("BLOCK:")
    game(univ, 4, 4, 3);
    print ("");
}

method blinker(){
    var univ := construct(5,5)
    
    univ[2][3] := 1;
    univ[3][3] := 1;
    univ[4][3] := 1;
    
    print ("BLINKER:")
    game(univ, 5, 5, 5);
    print ("");
}

method glider(){
    var univ := construct(5,5)
    
    univ[4][2] := 1;
    univ[4][3] := 1;
    univ[4][4] := 1;
    univ[3][4] := 1;
    univ[2][3] := 1;
    
    print ("GLIDER:")
    game(univ, 5, 5, 55);
    print ("");
}

//block();
//blinker();
glider();
