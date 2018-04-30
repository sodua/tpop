readFile := method(fileName,
file := File with(fileName) open
words := file readToEnd
file close
numchars := words split(" ", "\n")
data := List clone
for(i, 0, numchars size - 1,
    data append(numchars at(i) asNumber)
    )
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
)

buildHeap := method(data,
for(i, 0, data size - 1,
    upHeap(data, i)
    )
)

downHeap := method(data, n, stop,
left := leftChildIndex(n)
right := rightChildIndex(n)
if(left >= stop) then(return) elseif (left < stop) and (right >= stop) then(
    if(data at(n) < data at(left)) then(
        temp := data at(n)
        data atPut(n, data at(left))
        data atPut(left, temp)
        downHeap(data, left, stop)
        ) else (return)
    ) else(
    if(data at(n) >= data at(left) and data at(n) >= data at(right)) then(return) else(
        largestChild := left
        if(data at(left) < data at(right)) then(
            largestChild := right)
        temp := data at(n)
        data atPut(n, data at(largestChild))
        data atPut(largestChild, temp)
        downHeap(data, largestChild, stop)
    )
        )
)

sortHeap := method(data,
n := data size
for(i, n-1, 1, -1,
    temp := data at(0)
    data atPut(0, data at(i))
    data atPut(i, temp)
    downHeap(data, 0, i)
)
)

drawTree := method(data,
n := data size
)

sortData := method(data,
buildHeap(data)
sortHeap(data)
data println
)

processData := method(data,
sortData(data)
)

processData(readFile ("data.txt"))
processData(list(5,8,1,12,3,4,7))
