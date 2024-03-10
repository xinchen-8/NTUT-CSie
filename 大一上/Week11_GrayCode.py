num = []

while 1:
    register = input().split()
    if register[0] == '-1': break
    else:
        num.append([int(i) for i in register])

ans = ['' for _ in range(len(num))]

def Gray(index:int,n,k):
    if n==1: ans[index] += str(k)
    elif k < 2**(n-1):
        ans[index] += '0'
        Gray(index,n-1,k)
    elif k >= 2**(n-1):
        ans[index] += '1'
        Gray(index,n-1,2**n-1-k)
    
index = 0
for n,k in num:
    Gray(index,n,k)
    print(ans[index])
    index += 1