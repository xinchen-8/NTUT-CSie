Score = 0
score = []

score.append(int(input()))
if score[0]==10:                            #10,X,X...
    score.append(int(input()))
    if score[1]==10:                                                #10,10,X,X
        score.append(int(input()))
        score.append(int(input()))
        Score = score[0]+score[1]*2+score[2]*2+score[3]
    else:                                   #10,8,X...    
        score.append(int(input()))
        if score[1]+score[2]==10:                                   #10,8,2,X
            score.append(int(input()))
            Score = score[0]+score[1]*2+score[2]*2+score[3]
        else:                                                       #10,8,1
            Score = score[0]+score[1]*2+score[2]*2
else:                                       #2,X,X...
    score.append(int(input()))
    if score[0]+score[1]==10:               #2,8,X,X...
        score.append(int(input()))
        if score[2]==10:                                            #2,8,10,X,X
            score.append(int(input()))
            score.append(int(input()))
            Score = score[0]+score[1]+score[2]*2+score[3]+score[4]
        else:                               #2,8,2,X...
            score.append(int(input()))
            if score[2]+score[3]==10:                               #2,8,2,8,X
                score.append(int(input()))
                Score = score[0]+score[1]+score[2]*2+score[3]+score[4]
            else:                                                   #2,8,2,7
                Score = score[0]+score[1]+score[2]*2+score[3]
    else:                                   #2,7,X,X...
        score.append(int(input()))
        if score[2]==10:                                            #2,7,10,X,X
            score.append(int(input()))
            score.append(int(input()))
            Score = score[0]+score[1]+score[2]+score[3]+score[4]
        else:                               #2,7,2,X...
            score.append(int(input()))
            if score[2]+score[3]==10:                               #2,7,2,8,X
                score.append(int(input()))
                Score = score[0]+score[1]+score[2]+score[3]+score[4]
            else:                                                   #2,7,2,7
                Score = score[0]+score[1]+score[2]+score[3]
print(Score)