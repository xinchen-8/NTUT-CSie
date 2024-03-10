school = {}
reglist = [input().split() for _ in range(int(input()))]
for i in reglist: school[i[0]] = i[1::]
#print(school)

searchlist = [list(map(lambda x: x.split(),input().split('+')))for _ in range(int(input()))]
mode = int(input())

def findingwide(checklist:list)->dict:#[['GF','BC'],['NC']]
    searchschool = {}
    for key, value in school.items():
        weight = 0
        for condition in checklist:
            if all(map(lambda x: x in value, condition)): weight += 1
        if weight: searchschool[key] = weight
    return searchschool

def findingnarrow(checkdoublelist:list)->dict:
    checklist = []
    for index in checkdoublelist:
        for element in index:
            checklist.append(element)
    #print(checklist)
    
    searchschool = {}
    for key, value in school.items():
        weight = 0
        for element in checklist:
            if element in value: weight += 1
        if weight: searchschool[key] = weight
    return searchschool


for index in searchlist:
    if mode==0:
        checkdict = findingwide(index)
        print(*list(checkdict.keys()))
    else:
        checkdict = findingnarrow(index)
        checkdict = sorted(checkdict.items(), key=lambda x: x[1],reverse=True)
        for key, value in checkdict:
            if value == checkdict[0][1]: print(key, end=' ')
            else: break
        print()


