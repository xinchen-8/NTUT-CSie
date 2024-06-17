Within_voice= int(input())
Outside_voice = int(input())
LocalCall = int(input())
Within_message = int(input())
Outside_message = int(input())
NerworkTraffic = int(input())

#cost,voice[in,out,local],NT[contain,cost]
TypeOfCost = [[183,[0.08,0.139,0.135],[1,250]],[383,[0.07,0.13,0.121],[3,200]],[983,[0.06,0.108,0.101],[5,150]],[1283,[0.05,0.1,0.09],["full"]]]
TypeOfCost_message = [1.128,1.483]

TotalOfType = [0,0,0,0]
Round = 0
for i in TypeOfCost:
    TotalOfType[Round]+=i[1][0]*Within_voice
    TotalOfType[Round]+=i[1][1]*Outside_voice
    TotalOfType[Round]+=i[1][2]*LocalCall
    TotalOfType[Round]+=TypeOfCost_message[0]*Within_message
    TotalOfType[Round]+=TypeOfCost_message[1]*Outside_message
    if i[2][0] == "full": None
    elif NerworkTraffic>i[2][0]:
        TotalOfType[Round]+=(NerworkTraffic-i[2][0])*i[2][1]
    if TotalOfType[Round]<i[0]:
        TotalOfType[Round]=i[0]
    Round+=1

MinIndex = 0
for i in range(4):
    if TotalOfType[i]<TotalOfType[MinIndex]:
        MinIndex = i

print(int(TotalOfType[MinIndex]))
print(TypeOfCost[MinIndex][0])
