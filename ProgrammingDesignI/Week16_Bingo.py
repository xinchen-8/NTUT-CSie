numoflen = int(input())
numofchoose = int(input())

regA = list(map(int,input().split()))
regB = list(map(int,input().split()))

choose = list(map(int,input().split()))
for i in choose:
    regA[regA.index(i)] = 0
    regB[regB.index(i)] = 0

Aarray = [regA[i:i+numoflen] for i in range(0,len(regA),numoflen)]
Barray = [regB[i:i+numoflen] for i in range(0,len(regB),numoflen)]
counterA, counterB = 0, 0

#row
for i in range(numoflen):
    if Aarray[i].count(0)==numoflen: counterA += 1
    if Barray[i].count(0)==numoflen: counterB += 1

#column
matrixA_turnright = [[Aarray[numoflen-1-j][i] for j in range(numoflen)]for i in range(numoflen)]
matrixB_turnright = [[Barray[numoflen-1-j][i] for j in range(numoflen)]for i in range(numoflen)]

for i in range(numoflen):
    if matrixA_turnright[i].count(0)==numoflen: counterA += 1
    if matrixB_turnright[i].count(0)==numoflen: counterB += 1

#slope1
regA = []; regB = []
for i in range(numoflen):
    regA.append(Aarray[i][i])
    regB.append(Barray[i][i])
if regA.count(0)==numoflen: counterA += 1
if regB.count(0)==numoflen: counterB += 1

#slope2
regA = []; regB = []
for i in range(numoflen):
    regA.append(Aarray[i][numoflen-1-i])
    regB.append(Barray[i][numoflen-1-i])
if regA.count(0)==numoflen: counterA += 1
if regB.count(0)==numoflen: counterB += 1

if counterA > counterB:
    print('A Win')
elif counterB > counterA:
    print('B Win')
else:
    print('Tie')