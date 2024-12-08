import re
file = open("input.txt", "r")

lines = file.readlines()


# -----------PART  ONE---------------

xmas = re.compile("XMAS")
samx = re.compile("SAMX")


def countHorizontal():
    count = 0
    for line in lines:
        for j in range(len(line)-3):
            str = line[j] + line[j+1] + line[j+2] + line[j+3]
            if xmas.search(str) or samx.search(str):
                count += 1
    
    return count


def countVertical():
    count = 0
    for i in range(len(lines)-3):
        for j in range(len(lines[i])-1):
            str = lines[i][j] + lines[i+1][j] + lines[i+2][j] + lines[i+3][j]
            if xmas.search(str) or samx.search(str):
                    count += 1
    return count


def countDiagonalRight():
    count = 0
    for i in range(len(lines)-3):
         for j in range(len(lines[i])-4):
            str = lines[i][j] + lines[i+1][j+1] + lines[i+2][j+2] + lines[i+3][j+3]
            if xmas.search(str) or samx.search(str):
                    count += 1
    return count


def countDiagonalLeft():
    count = 0
    for i in range(len(lines)-3):
        for j in range(len(lines[i])):
            str = lines[i][j] + lines[i+1][j-1] + lines[i+2][j-2] + lines[i+3][j-3]
            if xmas.search(str) or samx.search(str):
                    count += 1
    return count
    

print("PART ONE ", countHorizontal()+countVertical()+countDiagonalRight()+countDiagonalLeft())



#----------------PART TWO-----------------

mas = re.compile("MAS")
sam = re.compile("SAM")

def checkXMas():
    count = 0
    for i in range(len(lines)-2):
         for j in range(len(lines[i])-3):
            str = lines[i][j] + lines[i+1][j+1] + lines[i+2][j+2]
            if mas.search(str) or sam.search(str):
                    str2 = lines[i][j+2] + lines[i+1][j+1] + lines[i+2][j]
                    if mas.search(str2) or sam.search(str2):
                        count += 1
    return count

print("PART TWO", checkXMas())