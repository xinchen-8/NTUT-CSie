
List = [[380,[],'A'],[1200,[],'B'],[180,[],'C']]

a = [int(x)for x in input().split(',')]; List[0][1] = a
b = [int(x)for x in input().split(',')]; List[1][1] = b
c = [int(x)for x in input().split(',')]; List[2][1] = c

Sum = {}
for i in List:
    sum = i[0]*i[1][0]
    if 11<=i[1][0] and i[1][0]<=20:
        sum*=i[1][1]/100    
    elif 21<=i[1][0] and i[1][0]<=30:
        sum*=i[1][2]/100
    elif i[1][0]>30:
        sum*=i[1][3]/100
    Sum[i[2]] = int(sum+0.9)

sorted_dict = dict(sorted(Sum.items(), key=lambda item: item[1], reverse=True))

total = 0
for key, value in sorted_dict.items():
    print(f'{key},{value}')
    total+=value
print(total)
