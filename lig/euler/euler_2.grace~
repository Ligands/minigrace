import "mgcollections" as col

var sum := 0
var a := 1
var b := 1
while{b < 4000000} do {
    if((b % 2) == 0) then { sum := sum + b }
    var tmp := b
    b := a + b
    a := tmp
}

print(sum)
