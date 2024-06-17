C = int(input())
N = int(input())

if N%2==0 or N<=2 or N>=50:
    print("error")

else:
    if C==1:
        for i in range(N):
            for j in range(N*2-1):
                if j<=N-1+i and j>=N-1-i :
                    print('*',end='')
                else: 
                    print('#',end='')
            print()
    if C==2:
        for i in range(N):
            for j in range(N*2-1):
                if j>=i and j<=N*2-2-i :
                    print('*',end='')
                else: 
                    print('#',end='')
            print()
    if C==3:
        for i in range(N):
            for j in range(N):
                if (i<=(N-1)/2 and j<=(N-1)/2+i and j>=(N-1)/2-i)or(i>(N-1)/2 and j>=i-(N-1)/2 and j<=N+(N-1)/2-i-1) :
                    print('*',end='')
                else:
                    print(' ',end='')
            print()
    if C==4:
        for i in range(N):
            for j in range(N+int(N/2)+1):
                if (i<=(N-1)/2 and j<=(N-1)/2+i and j>=(N-1)/2-i)or(i>(N-1)/2 and j>=i-(N-1)/2 and j<=N+(N-1)/2-i-1) :
                    print('*',end='')
                elif (i<=(N-1)/2 and j>=N+N/2-i-1 and j<=N+N/2-1)or(i>(N-1)/2 and j>=i+N-(N-1)/2 and j<=N+N/2-1):
                    print('-',end='')
                else:
                    print(' ',end='')
            print()