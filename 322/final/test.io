data := (list(1,2,3,4,5))
n := data size
for(i, n-1, 0, -1,
    temp := data at(0)
    data atPut(0, data at(i))
    data atPut(i, temp)
    i println
)
data println
