x = []

while 1:
    reg = input()

    if reg == '-1': break
    elif reg =='0': continue
    else: x.append(reg)


def BtoD(num:str) -> int:
    count = 0
    index = 0
    for i in range(len(num)-1,-1,-1):
        count += int(num[i])*2**index
        index += 1
    return count

def C(num:int,turn) -> int:
    if num == 0 or num == 1:
        print(DtoB(turn+1,0))
        return num
    elif num%2 == 0: return C(num/2,turn+1)
    else: return C((num+1)/2,turn+1)

def DtoB(num:int,weight:int) -> str:
    if num>=1:
        return DtoB(num//2,weight+1) + str(num % 2)
    elif weight<4:
        return DtoB(num,weight+1) + '0'
    else: return ''


for i in x:
    C(BtoD(i),-1)