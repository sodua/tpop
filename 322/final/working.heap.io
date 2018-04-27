readFile := method(fileName,
file := File with(fileName) open
words := file readToEnd
file close
data := words split("\n", " ")
)

processData := readFile ("data.txt")
processData foreach(v, v println)
