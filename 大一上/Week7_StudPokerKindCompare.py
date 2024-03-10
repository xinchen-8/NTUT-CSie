CardRecorder = []
def Cards(CardList:list)->int:
    global CardRecorder
    KindOfCard = {'S':0,'H':1,'D':2,'C':3}
    NumOfCard = ['A','2','3','4','5','6','7','8','9','10','J','Q','K']

    #Special Case
    ErrorInput = False
    DuplicateDeal = False

    for i in CardList:
        if (i[-1] not in KindOfCard) or (i[:-1] not in NumOfCard): ErrorInput = True
        elif CardList.count(i)>1 or (i in CardRecorder): DuplicateDeal = True
    if ErrorInput: return -1
    elif DuplicateDeal: return -2
    else:
        #sort
        CardList = sorted(CardList,key=lambda x: NumOfCard.index(x[:-1]))
        CardRecorder.extend(CardList)
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

Mylist ={}
n = int(input())
for _ in range(n):
    player = input().split()
    Mylist[player[0]] = Cards(player[1:])
Mylist = dict(sorted(Mylist.items(),key=lambda x:x[1],reverse=True))
#print(Mylist.items)
if -2 in Mylist.values() or -1 in Mylist.values():
    if -1 in Mylist.values():
        print('Error input')
    else:
        print('Duplicate deal')
else:
    for key,value in Mylist.items():
        print(key,value)