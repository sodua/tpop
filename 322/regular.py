#!/usr/bin/python
import re
import sys

text2=sys.argv[1]


regex_num=re.compile('^[+-]?[1-9]+[0-9]+$')
s = regex_num.search(text2)

print('Starting position: ', s.start())
print('Ending position: ', s.end())
print(text2[s.start():s.end()])
