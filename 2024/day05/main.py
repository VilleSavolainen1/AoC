file = open("input.txt", "r")

lines = file.readlines()
rules = []
pageNumbers = []
midCount = 0
correctedMidCount = 0
inCorrects = []

for line in lines:
    if len(line) > 0 and len(line) <= 6 and len(line) != 1:
        rule1 = line.split("|")
        rule2 = rule1[1].split("\n")
        rules.append([rule1[0], rule2[0]])
    if len(line) > 6:
        pageNumbers.append(line.split(","))
        
def checkOrder(page):
    indexOne = 0
    indexTwo = 0
    for rule in rules:
        if rule[0] in page and rule[1] in page:
            for i in range(len(page)):
                if '\n' in page[i]:
                    page[i] = page[i].replace('\n', '')
                if int(page[i]) == int(rule[0]):
                    indexOne = i
                if int(page[i]) == int(rule[1]):
                    indexTwo = i
            if indexOne > indexTwo:
                return False
    return True


for page in pageNumbers:
    if checkOrder(page):
        midCount += int(page[int((len(page)) / 2)])
    else:
        inCorrects.append(page)


def orderPages(inCorrect):
    indexOne = 0
    indexTwo = 0
    midNum = 0
    for rule in rules:
        if rule[0] in inCorrect and rule[1] in inCorrect:
            for i in range(len(inCorrect)):
                if int(inCorrect[i]) == int(rule[0]):
                    indexOne = i
                if int(inCorrect[i]) == int(rule[1]):
                    indexTwo = i
            if indexOne > indexTwo:
                temp = inCorrect[indexOne]
                inCorrect[indexOne] = inCorrect[indexTwo]
                inCorrect[indexTwo] = temp
                orderPages(inCorrect)
            else:
                midNum = int(inCorrect[int((len(inCorrect)) / 2)])
    return midNum
                

for page in inCorrects:
    correctedMidCount += orderPages(page)
        

print("PART ONE ", midCount)
print("PART TWO ", correctedMidCount)
