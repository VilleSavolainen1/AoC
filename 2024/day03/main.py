import re
file = open("input.txt", "r")

lines = file.readlines()

def countInstructions(line):
    res = 0
    pattern = re.compile("mul\(\d{1,},\d{1,}\)")
    numbers = re.compile("\d{1,},\d{1,}")
    match = pattern.findall(line)
    for j in range(len(match)):
        pair = numbers.findall(match[j])
        for k in pair:
            res += (int(k.split(",")[0]) * int(k.split(",")[1]))
    return res


def partOne():
    result = 0
    for i in range(len(lines)):
        result += countInstructions(lines[i])
    return result

def checkDisabled():
    enable = re.compile("do\(\)")
    disable = re.compile("don't\(\)")
    corrected = ""
    isEnabled = True
    for line in lines:
        for i in range(len(line)):
            if i < len(line) - 3:
                if enable.search(line[i] + line[i+1] + line[i+2] + line[i+3]):
                    isEnabled = True
            if i < len(line) - 6:
                if disable.search(line[i] + line[i+1] + line[i+2] + line[i+3] + line[i+4] + line[i+5] + line[i+6]):
                    isEnabled = False          
            if isEnabled:
                corrected += line[i]
    return corrected

def partTwo():
    result = 0
    result += countInstructions(checkDisabled())
    return result

# Part one
print("PART ONE", partOne())
# Part two
print("PART TWO ", partTwo())

file.close()