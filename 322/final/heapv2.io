readFile := method(fileName,
file := File with(fileName) open
words := file readToEnd
file close
data := words split("\n", " ")
)

buildHeap := method(data,
n := data size
return n
)

sortData := method(data,
n := buildHeap(data)
return n 
)

processData := method(data,
heap := sortData(data)
heap println
)

processData(readFile ("data.txt"))
processData(list(5,8,1,12,3,4,7))
