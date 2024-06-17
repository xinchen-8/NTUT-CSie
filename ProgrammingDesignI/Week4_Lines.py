full_lattice = []#-19...0...20
turn = int(input())

for _ in range(turn):
    
    reg = [int(i) for i in input().split()]

    for i in range(reg[0]+1,reg[1]+1):
        if i not in full_lattice:
            full_lattice.append(i)

print(len(full_lattice))