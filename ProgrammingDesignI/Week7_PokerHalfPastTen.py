setting = {'A':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'10':10,'J':0.5,'Q':0.5,'K':0.5}

def DrawCards(point:float):
    global setting
    card = input()
    return point+setting[card]

player_card = DrawCards(0)
computer_card = DrawCards(0)

DonePlayer = False
DoneComputer = False

while not DonePlayer or not DoneComputer:
    
    if not DonePlayer:
        if input()=='Y':
            player_card = DrawCards(player_card)
            if player_card > 10.5:
                player_card = 0
                break
        else: DonePlayer = True

    if not DoneComputer:
        if computer_card < player_card or computer_card <= 8:
            computer_card = DrawCards(computer_card)
            if computer_card > 10.5:
                computer_card = 0
                break
        else: DoneComputer = True

if player_card == computer_card: print('it\'s a tie')
elif player_card > computer_card: print('player win')
else: print('computer win')