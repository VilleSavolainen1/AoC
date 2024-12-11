file = open("input.txt", "r")

lines = file.readlines()
col, row = 0, 0
direction = "up"
positions = 1
visited = []

for i in range(0, len(lines)):
    for j in range(0, len(lines[i])):
        if "^" in lines[i][j]:
            col = i
            row = j
            break

while True:
    if direction == "up":
        if col < 1:
            break
        if lines[col-1][row] == "#":
            direction = "right"
        else:
            visited.append((col, row))
            col -= 1
            if (col, row) not in visited:
                positions += 1
    if direction == "right":
        if row >= len(lines[col])-1:
            break
        if lines[col][row+1] == "#":
            direction = "down"
        else:
            visited.append((col, row))
            row += 1
            if (col, row) not in visited:
                positions += 1
    if direction == "down":
        if col >= len(lines)-1:
            break
        if lines[col+1][row] == "#":
            direction = "left"
        else:
            visited.append((col, row))
            col += 1
            if (col, row) not in visited:
                positions += 1
    if direction == "left":
        if row < 1:
            break
        if lines[col][row-1] == "#":
            direction = "up"
        else:
            visited.append((col, row))
            row -= 1
            if (col, row) not in visited:
                positions += 1


print("PART ONE ", positions)  
