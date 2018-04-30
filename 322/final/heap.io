# in-place heap sort in the Io language, ported from Python
# CSC 322 Final Project
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
if(n == 0) then(return) # the root has no parent, no upHeap possible
p := parentIndex(n)
if(n == 0) then(return) if(data at(p) >= data at(n)) then(return) else(
temp := data at(n)        # swap
data atPut(n, data at(p)) # swap
data atPut(p, temp)       # swap
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
# case 1: already a leave and case 2: only has a left child:
if(left >= stop) then(return) elseif (left < stop) and (right >= stop) then(
    if(data at(n) < data at(left)) then(
        temp := data at(n)              # swap
        data atPut(n, data at(left))    # swap
        data atPut(left, temp)          # swap
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
    temp := data at(0)          # swap, and sorted element i
    data atPut(0, data at(i))   # swap, and sorted element i
    data atPut(i, temp)         # swap, and sorted element i
    downHeap(data, 0, i)
    )
)

# the following inorder function is not fully debugged!
inorder := method(data, n, depth, 
nn := data size
ordered := clone List
if(n >= nn) then (return ())
left := leftChildIndex(n)
right := rightChildIndex(n)
isRightChild := (n % 2) == 0 # only exception is for the root
hasRightChild := (n * 2 + 2) < nn
inorder(data, left, depth+1)
ordered append(data at(n), depth, isRightChild, hasRightChild)
inorder(data, right, depth+1)
)

# the following updateBars function is not debugged!
updateBars := method(bars, depth, isRightChild, hasRightChild,
location1 := 5 * depth - 4 # location for level depth - 1
location2 := location1 + 5 # location for level depth
if(bars size < location2) then(
    bars := bars append(" ") * (location2 - bars size))
if(depth == 0) then(
    # this is the root, no bar to remove
    continue)
elseif(isRightChild) then(
    # remove the bar at level depth - 1
    bars := bars slice(0,location1)
    bars append(bars slice(location1+1,bars size))
    )
else(
    # add a bar at level depth - 1
    bars := bars slice(0,location1)
    bars append("|")
    bars append(slice(location1+1,bars size))
    )
(hasRightChild) ifFalse(
    # remove the bar at level depth, since no one else will remove it.
    bars := bars slice(0,location2)
    bars append(" ")
    bars append(bars slice(location2+1,bars size))
    )
return bars asMutable rstrip
)

# the following drawTree function is not debugged!
drawTree := method(data,
bars := " "
results := List clone
items := List clone
#items := inorder(data)
for(i, 0, items size - 1,
    results append(bars asString)
    valueStr := value asString
    (isRightChild) isFalse(
        bars := updateBars(bars, depth, isRightChild, hasRightChild))
    if(depth == 0) then(
        results append(valueStr))
    else(
        barPrefix := ((depth-1) * 5)
        results append(bars slice(0,barPrefix))
        results append(" +---")
        results append(valueStr))
    (isRightChild) ifTrue(
        bars := updateBars(bars, depth, isRightChild, hasRightChild))
    results append(bars asString)
    )
return(results)
)

sortData := method(data,
buildHeap(data)
result := drawTree(data)
sortHeap(data)
)

verifySorted := method(data,
n := data size
if (n < 2) then (return true) else(
    # list of length less than two is sorted by definition
    for(i, 1, n,
        if(data at(i-1) > data at(i)) then(return false)) else(return(true))
            )
    )

processData := method(data,
sortData(data)
if(verifySorted(data) != true) then ("***** Warning: Data is not sorted. *****" println)
data println
)

processData(readFile("data.txt"))
processData(list(5,8,1,12,3,4,7))
