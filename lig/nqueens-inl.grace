import "sys" as sys
def N : Number = 9
var b := 1..N
var s := 0;
method inline{}
method unsafe(y) is inline {
    var x := b[y+1]
    for(1..y) do { i->
        var t := b[(y - i)+1]
        if((t == x) ||
            (t == (x - i)) ||
            (t == (x + i))) then {
            return true
        }
    }
    false
}
var avg := 0
method main(n){
    var time := sys.cputime
    var y := 0
    b[1] := -1
    while{y >= 0} do {
        b[y+1] := b[y+1] + 1
        var safe := unsafe(y)
        while{(b[y+1] < N) && safe} do {
            b[y+1] := b[y+1] + 1
            safe := unsafe(y)
        }
        if(b[y+1] < N) then {
            if(y < (N-1)) then {
                y := y + 1
                b[y+1] := -1;
            }
        } else {
            y := y - 1
        }
    }
    var tt:=(sys.cputime - time)
    avg := avg + tt
    print("Run {n}: {tt}s")
}
for(1..15) do { i ->
    main(i)
}
print("average : {avg/15}s")
