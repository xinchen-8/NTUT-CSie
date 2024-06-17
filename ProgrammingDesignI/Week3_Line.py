Astart = int(input())
Aend = int(input())
Bstart = int(input())
Bend = int(input())
Cstart = int(input())
Cend = int(input())
full_lattice = []#-19...0...20


for i in range(Astart+1,Aend+1):
    full_lattice.append(i)

for i in range(Bstart+1,Bend+1):
    if i not in full_lattice:
        full_lattice.append(i)

for i in range(Cstart+1,Cend+1):
    if i not in full_lattice:
        full_lattice.append(i)

print(len(full_lattice))