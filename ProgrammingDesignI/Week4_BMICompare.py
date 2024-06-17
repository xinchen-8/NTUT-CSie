def Float(A:float)->float:
    if int(A*1000)%10>5 or (int(A*1000)%10==5 and int(A*100)%2!=0): A = int(A*100+1)/100
    else: A = int(A*100)/100
    return A

BMI = []
turn = int(input())
for _ in range(turn):
    reg = [float(i) for i in input().split()]
    BMI.append(Float(reg[1]/reg[0]**2))

#MAX
BMI.sort(reverse=True); print("%.2f"%BMI[0])#.2f防止整除例外:20.0
#MIN
BMI.sort(reverse=False); print("%.2f"%BMI[0])
#MEDIUM
if turn%2==0:
    print("%.2f"%Float((BMI[int(turn/2)-1]+BMI[int(turn/2)])/2))
else:
    print("%.2f"%BMI[int(turn/2)])
#Mode
Times = []
for i in BMI:
    time = 0
    for j in BMI:
        if i==j: time+=1
    Times.append(time)
index = 0
for i in range(len(Times)):
    if Times[i]>Times[index] or (Times[i]==Times[index] and BMI[i]<BMI[index]): index = i
print("%.2f"%BMI[index])