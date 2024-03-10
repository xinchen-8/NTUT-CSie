from math import sqrt
#code:[x,y,z]
Drones = {}
for _ in range(int(input())):
    reg_input = input().split()
    Drones[int(reg_input[0])] = list(map(lambda x:int(x), reg_input[1:]))
#print(Drones)

distance = []
for i in range(1,len(Drones)+1):
    for j in range(i+1,len(Drones)+1):
        reg_distance = sqrt((Drones[i][0]-Drones[j][0])**2+(Drones[i][1]-Drones[j][1])**2+(Drones[i][2]-Drones[j][2])**2)
        distance.append([i,j,reg_distance]+Drones[i]+Drones[j])

distance = sorted(distance, key=lambda x:x[2])
for i in range(3):
    print(*distance[i][:2],*distance[i][3:])