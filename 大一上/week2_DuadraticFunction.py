from math import sqrt

a = int(input())
b = int(input())
c = int(input())

if b**2-4*a*c>=0:
    print("%.1f"%((-b+sqrt(b**2-4*a*c))/(2*a)))
    print("%.1f"%((-b-sqrt(b**2-4*a*c))/(2*a)))
else:
    print("%.1f+%.1fi"%(-b/(2*a),sqrt(-b**2+4*a*c)/(2*a)))
    print("%.1f-%.1fi"%(-b/(2*a),sqrt(-b**2+4*a*c)/(2*a)))