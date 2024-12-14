import copy

file = open("input.txt", "r")

lines = file.readlines()
col, row = 0, 0
startCol, startRow = 0, 0
direction = "up"
visited = set()
positions = 1


for y, line in enumerate(lines):
    for x, char in enumerate(line):
        if char == "^":
            row, col = x, y


while True:
    if direction == "up":
        if col < 1:
            break
        if lines[col-1][row] == "#":
            direction = "right"
        else:
            visited.add((col, row))
            col -= 1
            if (col, row) not in visited:
                positions += 1
    if direction == "right":
        if row >= len(lines[col])-1:
            break
        if lines[col][row+1] == "#":
            direction = "down"
        else:
            visited.add((col, row))
            row += 1
            if (col, row) not in visited:
                positions += 1
    if direction == "down":
        if col >= len(lines)-1:
            break
        if lines[col+1][row] == "#":
            direction = "left"
        else:
            visited.add((col, row))
            col += 1
            if (col, row) not in visited:
                positions += 1
    if direction == "left":
        if row < 1:
            break
        if lines[col][row-1] == "#":
            direction = "up"
        else:
            visited.add((col, row))
            row -= 1
            if (col, row) not in visited:
                positions += 1

print("PART ONE: ", positions)


            

