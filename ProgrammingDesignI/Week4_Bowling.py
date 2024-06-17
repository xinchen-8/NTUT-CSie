turn = 1
Balls = []

#input
while turn<=10:#每局一圈
    reg_1 = int(input()); Balls.append(reg_1)
    if reg_1!=10:
        reg_2 = int(input()); Balls.append(reg_2)
        if reg_1+reg_2==10 and turn==10: Balls.append(int(input()))
    elif turn==10:
        Balls.append(int(input()))
        Balls.append(int(input()))
    turn+=1

#score
score,turn,index = 0,1,0
while turn<=10:
    if Balls[index]==10:
        score+=Balls[index]+Balls[index+1]+Balls[index+2]; index+=1
    else:
        if Balls[index]+Balls[index+1]==10:
            score+=Balls[index]+Balls[index+1]+Balls[index+2]; index+=2
        else:
            score+=Balls[index]+Balls[index+1]; index+=2
    turn+=1
print(score)