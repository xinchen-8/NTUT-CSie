point_dict = {'A':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'10':10,'J':0.5,'Q':0.5,'K':0.5}

players_num = int(input())
money = [int(x) for x in input().split()]; money.insert(0,0)

#first cards( 0 is computer
points = [point_dict[x] for x in input().split()]

#player input
for i in range(1,players_num+1):
    while 1:
        register = input().split()
        if register[0] == 'N':  break
        elif points[i]+point_dict[register[1]]<10.5:   points[i] += point_dict[register[1]]
        elif points[i]+point_dict[register[1]]==10.5:
            points[i] += point_dict[register[1]]
            money[0] -= money[i]
            break
        else:
            points[i] = -1
            money[0] += money[i]
            money[i] *= -1
            break

#computer input
smallest_point_of_player = 12
for i in points[1:]:
    smallest_point_of_player = i if i!=-1 and i<smallest_point_of_player else smallest_point_of_player

if smallest_point_of_player!=12 and smallest_point_of_player!=10.5:
    while smallest_point_of_player >= points[0]:
        register = input()
        if points[0]+point_dict[register]<=10.5:
            points[0] = points[0] + point_dict[register]
        else:
            points[0] = -1
            for i in range(1,players_num+1):
                if points[i]!=-1:
                    money[0] -= money[i]
            break
    #compare 
    if points[0]!=-1:
        for i in range(1,players_num+1):
            if points[i]!=-1 and points[i]!=10.5:
                if points[i]<=points[0]:
                    money[0] += money[i]
                    money[i] *= -1
                else:
                    money[0] -= money[i]
#output

for i in range(1,players_num+1):
    #print(points[i])
    #print(money[i])
    print(f'Player{i} +{money[i]}') if money[i] > 0 else print(f'Player{i} {money[i]}')
#print(points[0])
print(f'Computer +{money[0]}') if money[0] > 0 else print(f'Computer {money[0]}')