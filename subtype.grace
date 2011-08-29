
import util

def types = []
def matrix = HashMap.new

method resetMatrix {
    for (types) do {t->
        def inner = HashMap.new
        for (types) do {t2->
            inner.put(t2.value, true)
        }
        matrix.put(t.value, inner)
    }
}

method addType(t) {
    if (matrix.contains(t.value)) then {
        return false
    }
    if (t.unionTypes.size > 0) then {
        for (t.uniontypes) do {ut->
            addType(ut)
        }
    }
    types.push(t)
    def inner = HashMap.new
    for (types) do {t2->
        inner.put(t2.value, true)
        if (t2 /= t) then {
            matrix.get(t2.value).put(t.value, true)
        }
    }
    matrix.put(t.value, inner)
    true
}

method printMatrix {
    for (types) do {t->
        def row = matrix.get(t.value)
        var st := ""
        for (types) do {t2->
            if (row.get(t2.value)) then {
                st := "{st} {t2.value}"
            }
        }
        print("{t.value} is a subtype of:{st}")
    }
}
method findType(typeid) {
    if (typeid.kind == "type") then {
        return typeid
    }
    for (types) do {t->
        if (t.value == typeid.value) then {
            return t
        }
    }
    false
}

method simpleCheckThat(a)mayBeSubtypeOf(b) {
    matrix.get(a.value).get(b.value)
}
method checkThat(a)mayBeSubtypeOf(b) {
    if (a.value == "Dynamic") then {
        return true
    }
    if (b.value == "Dynamic") then {
        return true
    }
    if (matrix.get(a.value).get(b.value).not) then {
        return false
    }
    if (b.unionTypes.size > 0) then {
        for (b.unionTypes) do {ut->
            if (checkThat(a)mayBeSubtypeOf(findType(ut))) then {
                return true
            }
        }
        return false
    }
    if (a.methods.size < b.methods.size) then {
        return false
    }
    for (b.methods) do {bm->
        var found := false
        for (a.methods) do {am->
            if (am.value == bm.value) then {
                found := true
                if (simpleCheckThat(findType(am.rtype))mayBeSubtypeOf(findType(bm.rtype)).not) then {
                    return false
                }
                if (am.params.size /= bm.params.size) then {
                    return false
                }
                if (am.params.size > 0) then {
                    def mini = am.params.indices.first
                    def maxi = am.params.indices.last
                    def range = mini..maxi
                    for (range) do {i->
                        def ap = am.params.at(i)
                        def bp = bm.params.at(i)
                        if (simpleCheckThat(findType(bp.dtype))mayBeSubtypeOf(findType(ap.dtype)).not) then {
                            return false
                        }
                    }
                }
            }
        }
        if (!found) then {
            return false
        }
    }
    return true
}

method findSubtypes {
    var changed := true
    while {changed} do {
        changed := false
        for (types) do {t1->
            def row = matrix.get(t1.value)
            for (types) do {t2->
                if (row.get(t2.value)) then {
                    if (checkThat(t1)mayBeSubtypeOf(t2).not) then {
                        row.put(t2.value, false)
                        changed := true
                    }
                }
            }
        }
    }
}

method conformsType(a)to(b) {
    if (addType(a) | addType(b)) then {
        findSubtypes
    }
    matrix.get(a.value).get(b.value)
}

