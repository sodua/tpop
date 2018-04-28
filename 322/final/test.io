data := (list(1,2,3,4,5))
n := 4 
p := 3
temp := data at(n)
data atPut(n, data at(p)) 
data atPut(p, temp)
data println
