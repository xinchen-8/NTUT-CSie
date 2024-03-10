M = int(input())
N = int(input())

if M==1:
    for i in range(1,N+1):
        for j in range(i):
            print(j+1,end='')
        for k in range(i-1,0,-1):
            print(k,end='')
        print()

if M==2:
    for i in range(1,N+1):
        for _ in range(N-i):
            print('_',end='')
        for j in range(i):
            print(j+1,end='')
        for k in range(i-1,0,-1):
            print(k,end='')
        for _ in range(N-i):
            print('_',end='')
        print()


if M==3:
    for i in range(N,0,-1):
        for _ in range(N-i):
            print('_',end='')
        for j in range(i):
            print(j+1,end='')
        for k in range(i-1,0,-1):
            print(k,end='')
        for _ in range(N-i):
            print('_',end='')
        print()