def sortHeap(data):
    n = len (data)
    for i in range (n-1, 0, -1):
        data[0], data[i] = data[i], data[0]
data=[1,2,3,4,5]
sortHeap(data)
print data[:]
