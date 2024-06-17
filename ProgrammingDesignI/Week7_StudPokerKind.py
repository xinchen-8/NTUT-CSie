CardList = input().split()
KindOfCard = {'S':0,'H':1,'D':2,'C':3}
NumOfCard = ['A','2','3','4','5','6','7','8','9','10','J','Q','K']

#Special Case
ErrorInput = False
DuplicateDeal = False

for i in CardList:
    if (i[-1] not in KindOfCard) or (i[:-1] not in NumOfCard): ErrorInput = True
    elif CardList.count(i)>1: DuplicateDeal = True
if ErrorInput: print('Error input')
elif DuplicateDeal: print('Duplicate deal')
else:
    #sort
    CardList = sorted(CardList,key=lambda x: NumOfCard.index(x[:-1]))
    #print(CardList)

    #compare
    state = {'two_num':0,'three_num':0,'four_num':0,'same_suit':False,'continuous':False}
    state['continuous'] = all(NumOfCard.index(CardList[i][:-1])-NumOfCard.index(CardList[i+1][:-1])==-1 or NumOfCard.index(CardList[i][:-1])-NumOfCard.index(CardList[i+1][:-1])==-9 for i in range(len(CardList)-1))
    state['same_suit'] = all(i[-1]==CardList[0][-1] for i in CardList)
    NumberList = [i[:-1] for i in CardList]

    for i in NumOfCard:
        if NumberList.count(i)==4: state['four_num']+=1
        elif NumberList.count(i)==3: state['three_num']+=1
        elif NumberList.count(i)==2: state['two_num']+=1

    #output
    #Straight flush
    if state['continuous'] and state['same_suit']: print(9)
    #Four of a kind
    elif state['four_num']: print(8)
    #Full House
    elif state['three_num'] and state['two_num']: print(7)
    #Flush
    elif state['same_suit']: print(6)
    #Straight
    elif state['continuous']: print(5)
    #Three of a kind 
    elif state['three_num']: print(4)
    #Two pairs
    elif state['two_num']==2: print(3)
    #One pairs
    elif state['two_num']: print(2)
    #High Card
    else: print(1)