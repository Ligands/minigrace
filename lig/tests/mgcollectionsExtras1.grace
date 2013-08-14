import "mgcollections" as col

var l := col.list.new

l.push("a")
l.push("b")
l.push("c")
l.at(2)insert(1)
l.at(3)delete()

if(l[1] != "a") then { print ("fail: expected 'a', got {l[1]}") }
elseif(l[2] != 1) then { print ("fail: expected '1', got {l[2]}") }
elseif(l[3] != "c") then { print ("fail: expected 'c', got {l[3]}") }
else { print "pass" }
