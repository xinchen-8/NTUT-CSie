A = input()
B = input()
x = input()
y = input()


#output C
C = A + ' ' + B
C_list = C.split()
print(C)

#len of C
C_len = 0
for c in C_list: C_len += len(c)

A_list = A.split()
B_list = B.split()

#output D
D = ''
reg_list = (A + ' ' + B).split()
for i in range(len(reg_list)):
    if reg_list[i].lower()==x.lower(): reg_list[i] = y

for i in range(len(reg_list)):
    D += reg_list[i]
    if i!=len(reg_list)-1:
        D += ' '

D_list = D.split()
print(D)

#len of D
D_len = 0
for d in D_list: D_len += len(d)

#output len
print(C_len,D_len)

#output reverse
for d in range(len(D_list)):
    if D_list[d]==y:
        for i in range(len(D_list[d])-1,-1,-1): print(D_list[d][i],end='')
    else: print(D_list[d],end='')
    if d!=len(D_list)-1: print(' ',end='')
print()

#output jump
reg = 0
for i in range(0,len(C),abs(len(x)-len(y))):
    if reg==' ' and C[i]==' ':
        None
    else:
        print(C[i],end='')
    reg = C[i]