from math import sqrt

def Float(A:float)->float:
    if int(A*1000)%10>=5: A = int(A*100+1)/100
    else: A = int(A*100)/100
    return A

def Area(a:int,b:int,c:int)->float:
    s = (a+b+c)/2
    return Float(sqrt(s*(s-a)*(s-b)*(s-c)))

def TakeArea(element):
    return element[1]

turn = int(input())
Triangles = [["",0] for _ in range(turn)]

#input
reg = []
for i in range(turn):
    reg_0 = [int(i) for i in input().split()]
    reg_0.sort(reverse=True)
    reg.append(reg_0)


#main
for i in range(turn):
    if reg[i][0]<=0 or reg[i][1]<=0 or reg[i][2]<=0 or reg[i][1]+reg[i][2]<=reg[i][0] or reg[i][1]+reg[i][0]<=reg[i][2] or reg[i][0]+reg[i][2]<=reg[i][1]:
        Triangles[i][0] = "not a triangle"
    elif reg[i][0]==reg[i][1] and reg[i][1]==reg[i][2]:
        Triangles[i][0] = "equilateral triangle"; Triangles[i][1] = Area(reg[i][0],reg[i][1],reg[i][2])
    elif reg[i][0]==reg[i][1] or reg[i][1]==reg[i][2] or reg[i][0]==reg[i][2]:
        Triangles[i][0] = "isosceles triangle"; Triangles[i][1] = Area(reg[i][0],reg[i][1],reg[i][2])
    elif reg[i][0]**2 > reg[i][1]**2+reg[i][2]**2:
        Triangles[i][0] = "obtuse triangle"; Triangles[i][1] = Area(reg[i][0],reg[i][1],reg[i][2])
    elif reg[i][0]**2 < reg[i][1]**2+reg[i][2]**2:
        Triangles[i][0] = "acute triangle"; Triangles[i][1] = Area(reg[i][0],reg[i][1],reg[i][2])
    elif reg[i][0]**2 == reg[i][1]**2+reg[i][2]**2:
        Triangles[i][0] = "right triangle"; Triangles[i][1] = Area(reg[i][0],reg[i][1],reg[i][2])

#output
NoneButton = True
for i in Triangles:
    if i[1]!=0:
        print(f"{i[0]} {i[1]:.2f}")
        NoneButton = False
    else:
        print(i[0])
if NoneButton:
    print("All inputs are not triangles!")
else:
    triangles = []
    for i in Triangles:
        if i[0]!="not a triangle":
            triangles.append(i)
    triangles.sort(key=TakeArea,reverse=True)
    print("%.2f"%triangles[0][1])
    print("%.2f"%triangles[-1][1])