CardRecorder = []
def Cards(CardList:list)->int:
    global CardRecorder
    KindOfCard = {'S':0,'H':1,'D':2,'C':3}
    NumOfCard = ['A','2','3','4','5','6','7','8','9','10','J','Q','K']

    #Special Case
    ErrorInput = False
    DuplicateDeal = False

    for i in CardList:
        if (i[0] not in KindOfCard) or (i[1:] not in NumOfCard): ErrorInput = True
        elif CardList.count(i)>1 or (CardRecorder.count(i)>1): DuplicateDeal = True
    if ErrorInput: return 12
    elif DuplicateDeal: return 11
    else:
        #sort
        CardList = sorted(CardList,key=lambda x: NumOfCard.index(x[1:]))
        #CardRecorder.extend(CardList)
        #print(CardList)

        #compare
        state = {'two_num':0,'three_num':0,'four_num':0,'same_suit':False,'continuous':False}
        state['continuous'] = all(NumOfCard.index(CardList[i][1:])-NumOfCard.index(CardList[i+1][1:])==-1 or NumOfCard.index(CardList[i][1:])-NumOfCard.index(CardList[i+1][1:])==-9 for i in range(len(CardList)-1))
        state['same_suit'] = all(i[0]==CardList[0][0] for i in CardList)
        NumberList = [i[1:] for i in CardList]

        for i in NumOfCard:
            if NumberList.count(i)==4: state['four_num']+=1
            elif NumberList.count(i)==3: state['three_num']+=1
            elif NumberList.count(i)==2: state['two_num']+=1

        #output
        #Straight flush
        if state['continuous'] and state['same_suit']: return 9
        #Four of a kind
        elif state['four_num']: return 8
        #Full House
        elif state['three_num'] and state['two_num']: return 7
        #Flush
        elif state['same_suit']: return 6
        #Straight
        elif state['continuous']: return 5
        #Three of a kind 
        elif state['three_num']: return 4
        #Two pairs
        elif state['two_num']==2: return 3
        #One pairs
        elif state['two_num']: return 2
        #High Card
        else: return 1

Acard = input().split()
Bcard = input().split()
Globalcard = input().split()
CardRecorder.extend(Acard+Bcard+Globalcard)
Ahighest, Bhighest = 0, 0

#Globalcard = a,b,c,d; 1.a,b,c 2.b,c,d 3.c,d,a 4.d,a,b
for i in range(4):
    register = Cards(Acard + [Globalcard[i],Globalcard[(i+1)%4],Globalcard[(i+2)%4]])
    #print(register)
    if register > Ahighest: Ahighest = register
    register = Cards(Bcard + [Globalcard[i],Globalcard[(i+1)%4],Globalcard[(i+2)%4]])
    #print(register)
    if register > Bhighest: Bhighest = register

#0,a,b,c,d 1,a,b,c,d
for i in range(2):
    register = Cards([Acard[i]] + Globalcard)
    #print(register)
    if register > Ahighest: Ahighest = register
    register = Cards([Bcard[i]] + Globalcard)
    #print(register)
    if register > Bhighest: Bhighest = register


#print(Ahighest)
#print(Bhighest)

if Ahighest==12 or Bhighest==12:
    print('Error input')
elif Ahighest==11 or Bhighest==11:
    print('Duplicate deal')
elif Ahighest==Bhighest:
    print('Tie')
elif Ahighest > Bhighest:
    print(f'A {Ahighest}')
else:
    print(f'B {Bhighest}')