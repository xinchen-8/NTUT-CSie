SubjectNum = 3
Subject_list = [0 for i in range(SubjectNum)]
TotalScore = 0

name = input()#one char
ID = int(input())

for i in range(SubjectNum):
    subject_list = int(input())
    TotalScore += subject_list

print(f'Name:{name}\nID:{ID}\nAverage:{int(TotalScore/SubjectNum)}\nTotal:{TotalScore}')