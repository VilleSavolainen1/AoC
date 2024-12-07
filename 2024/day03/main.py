import re
file = open("input.txt", "r")

lines = file.readlines()
result = 0
pattern = re.compile("mul\(\d{1,},\d{1,}\)")
numbers = re.compile("\d{1,},\d{1,}")

for i in range(len(lines)):
    match = pattern.findall(lines[i])
    for j in range(len(match)):
        pair = numbers.findall(match[j])
        for k in pair:
            result += (int(k.split(",")[0]) * int(k.split(",")[1]))

# Part one
print(result)

file.close()