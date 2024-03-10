def ScoreCounting(A:int)->float:
    global cards
    score = 0
    for i in cards[A]:
        if i=="A" or i=="J" or i=="Q" or i=="K":
            score+=0.5
        else:
            score+=int(i)
    return score

cards = [[],[]]

player = input()
for _ in range(3):  cards[0].append(input())
banker = input()
for _ in range(3):  cards[1].append(input())

scores = [ScoreCounting(0) if ScoreCounting(0)<=10.5 else 0,ScoreCounting(1) if ScoreCounting(1)<=10.5 else 0]

#rule1
if scores[0]==0 or scores[0]<scores[1]:
    print(f"{banker} Win")
elif scores[0]>scores[1]:
    print(f"{player} Win")
else:
    print("Tie")

#rule2
if scores[0]<scores[1]:
    print(f"{banker} Win")
elif scores[0]>scores[1]:
    print(f"{player} Win")
else:
    print("Tie")