readFile := method(fileName,
file := File with(fileName) open
words := file readToEnd
file close
data := words split("\n", " ")
)

parentIndex := method(index,
return (((index - 1) / 2) floor())
)

leftChildIndex := method(index,
return 2 * index + 1
)

rightChildIndex := method(index,
return 2 * index + 2
)

upHeap := method(data, n,
if(n == 0) then(return)
p := parentIndex(n)
if(n == 0) then(return) if(data at(p) >= data at(n)) then(return) else(
temp := data at(n)
data atPut(n, data at(p))
data atPut(p, temp)
upHeap(data, p)
)
data println
)

buildHeap := method(data,
for(i, 0, data size - 1,
    upHeap(data, i))
)

drawTree := method(data,
n := data size
)

sortData := method(data,
n := buildHeap(data)
result := drawTree(data)
/* sortHeap(data) */
return result 
)

processData := method(data,
heap := sortData(data)
)

processData(readFile ("data.txt"))
buildHeap(list(5,8,1,12,3,4,7))
