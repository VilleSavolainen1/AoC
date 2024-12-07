import re
import math
file = open("input.txt", "r")

lines = file.readlines()

matches = []
pairs = []
results = []
result = 0
pattern = re.compile("mul\(\d{1,},\d{1,}\)")
numbers = re.compile("\d{1,},\d{1,}")

for i in range(len(lines)):
    match = pattern.findall(lines[i])
    matches.append(match)
    
for i in range(len(matches)):
    for j in range(len(matches[i])):
        pair = numbers.findall(matches[i][j])
        for k in pair:
            result += (int(k.split(",")[0]) * int(k.split(",")[1]))


# Part one
print(result)

file.close()