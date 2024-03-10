
correct = True
get_out = 0

def IDCheck(c:str,List):
    global get_out
    try:int(c[-1:-5:-1])
    except:
        get_out-=1
    for i in range(len(c)-4):
        if ord(c[i])>=49 and ord(c[i])<=57:
            get_out-=1
    if c in List:
        get_out-=1
    return c

def HoursCheck(h:int):
    if h<1 or h>3:
        global get_out
        get_out-=1
    return h

def TimeCheck(t:str,List:list):
    if len(t)!=2 or ord(t[0])<49 or ord(t[0])>53 or (ord(t[1])<49 or (ord(t[1])>57 and ord(t[1])<97) or ord(t[1])>99) or t in List:
        global get_out
        get_out-=1
    return t

turn = int(input())
C = ['' for _ in range(turn)]
H = [0 for _ in range(turn)]
Clist = [[] for _ in range(turn)]

for i in range(turn):
    C[i] = IDCheck(input(),C)
    H[i] = HoursCheck(int(input()))
    Clist[i] = [''for j in range(H[i])]
    for j in range(H[i]):
        Clist[i][j] = TimeCheck(input(),Clist[i])

if get_out<0: print(-1)
else:
    for i in Clist[0]:
        for j in Clist[1]:
            if i==j: print(f'{C[0]},{C[1]},{i}'); correct = False
        for j in Clist[2]:
            if i==j: print(f'{C[0]},{C[2]},{i}'); correct = False
    for i in Clist[1]:
        for j in Clist[2]:
            if i==j: print(f'{C[1]},{C[2]},{i}'); correct = False
    if correct: print('correct')