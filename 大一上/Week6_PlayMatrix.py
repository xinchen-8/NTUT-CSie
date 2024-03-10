def TurnRight(n:int,matrix:list):
    new_matrix = [[matrix[n-1-j][i] for j in range(n)] for i in range(n)]    
    return new_matrix
#1 2 3   7 4 1
#4 5 6   8 5 2
#7 8 9   9 6 3
def TurnLeft(n,matrix:list):
    new_matrix = [[matrix[j][n-1-i] for j in range(n)] for i in range(n)]
    return new_matrix
#1 2 3   3 6 9
#4 5 6   2 5 8
#7 8 9   1 4 7

n = int(input())
turn = input()

matrix = [[i*n+j+1 for j in range(n)] for i in range(n)]

count = 0
for i in turn:
    if i=='L':  count-=1
    if i=='R':  count+=1

if count>0:
    #turn right
    for i in range(count):
        matrix = TurnRight(n,matrix)
elif count<0:
    #turn right
    for i in range(-count):
        matrix = TurnLeft(n,matrix)

#output
for i in matrix:
    for j in i:
        print(j,end=' ')
    print()