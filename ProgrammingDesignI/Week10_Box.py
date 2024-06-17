turn = int(input())
box = int(input())
mystring = [input() for _ in range(turn)]

box_sign = {'[':']','{':'}','(':')'}

for i in mystring:
    
    layer = 0
    layer_sign = []
    reg = ''
    fail = False

    ##every char in every string
    for s in i:
        try:
            if layer < 0:
                fail = True

            #left sign
            elif s in box_sign:
                layer += 1
                layer_sign.append(s)

            elif s in box_sign.values():
                if box_sign[layer_sign.pop()] == s:
                    layer -= 1
                else:
                    fail = True
                    
            elif layer == box and layer not in list(box_sign.keys())+list(box_sign.values()):
                reg += s

        except:
            fail = True

    if fail == True or layer!=0:
        print('fail')
    elif reg=='':
        print(f'pass, EMPTY')
    else:
        print(f'pass, {reg}')