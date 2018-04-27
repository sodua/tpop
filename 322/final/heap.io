readFile := method(fileName,
file := File with(fileName) open
fileText := file readToEnd
words := fileText
data := words split("\n", " ")
data at(99) println
)

readFile ("data.txt")
