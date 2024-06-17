high = float(input())
weight = float(input())
bmi = weight / high**2

if int(bmi*1000)%10==5:
    if int(bmi*100)%2==0:
        bmi-=0.01

print("%.2f"%bmi)