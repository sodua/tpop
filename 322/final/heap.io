readFile := method(fileName,
file := File with(fileName) open
words := file readToEnd
file close
data := words split("\n", " ")
)

processData := method(data,
return data size println
)

/* processData(readFile ("data.txt")) */
processData(list(5,8,1,12,3,4,7))
