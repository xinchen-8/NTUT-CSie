
#the list 4*4 [0][0]~[3][3]
Sudoku = [list(map(lambda x:int(x),input().split())) for y in range(4)]
#print(all([all(i) for i in Sudoku]))

while not (all([all(i) for i in Sudoku])):
     
    #row
    for i in range(4):
        reg_row = [Sudoku[i][x] for x in range(4)]
        if(0 in reg_row and len(set(reg_row)) == 4):
            Sudoku[i][reg_row.index(0)] = 10 - sum(reg_row)
          
    #column
    for i in range(4):
        reg_column = [Sudoku[x][i] for x in range(4)]
        if(0 in reg_column and len(set(reg_column)) == 4):
            Sudoku[reg_column.index(0)][i] = 10 - sum(reg_column)

    #block 00 01 10 11(+0+0), 02 03 12 13(+0+2), 20 21 30 31(+2+0), 22 23 32 33(+2+2)
    for index in range(4):
        reg_block = [Sudoku[0+(2 if index>1 else 0)][0+(2 if index%2==1 else 0)]]
        reg_block.append(Sudoku[0+(2 if index>1 else 0)][1+(2 if index%2==1 else 0)])
        reg_block.append(Sudoku[1+(2 if index>1 else 0)][0+(2 if index%2==1 else 0)])
        reg_block.append(Sudoku[1+(2 if index>1 else 0)][1+(2 if index%2==1 else 0)])
        if(0 in reg_block and len(set(reg_block)) == 4):
            if reg_block.index(0)==0: Sudoku[0+(2 if index>1 else 0)][0+(2 if index%2==1 else 0)] = 10 - sum(reg_block)
            elif reg_block.index(0)==1: Sudoku[0+(2 if index>1 else 0)][1+(2 if index%2==1 else 0)] = 10 - sum(reg_block)
            elif reg_block.index(0)==2: Sudoku[1+(2 if index>1 else 0)][0+(2 if index%2==1 else 0)] = 10 - sum(reg_block)
            else: Sudoku[1+(2 if index>1 else 0)][1+(2 if index%2==1 else 0)] = 10 - sum(reg_block)
        else: continue

for y in Sudoku:
    print(*y)