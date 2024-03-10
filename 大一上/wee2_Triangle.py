
def getTriangle(a,b,c):
    List = [a,b,c]
    List.sort(reverse = True)#降序
    return List

a = int(input())
b = int(input())
c = int(input())

TList = getTriangle(a,b,c)
if TList[0]<=0 or TList[1]<=0 or TList[2]<=0 or TList[1]+TList[2]<=TList[0] or TList[1]+TList[0]<=TList[2] or TList[0]+TList[2]<=TList[1]:
    print("not a triangle")
elif TList[0]==TList[1] and TList[1]==TList[2]:
    print("equilateral triangle")
elif TList[0]==TList[1] or TList[1]==TList[2] or TList[0]==TList[2]:
    print("isosceles triangle")
elif TList[0]**2 > TList[1]**2+TList[2]**2:
    print("obtuse triangle")
elif TList[0]**2 < TList[1]**2+TList[2]**2:
    print("acute triangle")
elif TList[0]**2 == TList[1]**2+TList[2]**2:
    print("right triangle")
