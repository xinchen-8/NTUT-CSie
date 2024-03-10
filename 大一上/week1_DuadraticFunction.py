import math

coef = [int(input()) for i in range(3)]

x1 = ((-coef[1])+math.sqrt(coef[1]**2-4*coef[0]*coef[2]))/(2*coef[0])
x2 = ((-coef[1])-math.sqrt(coef[1]**2-4*coef[0]*coef[2]))/(2*coef[0])

print("%.1f" %x1)
print("%.1f" %x2)