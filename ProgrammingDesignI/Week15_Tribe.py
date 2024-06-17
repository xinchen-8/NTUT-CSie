def main():
    
    #input points
    numofway, start, end = input().split()
    restpoints = input().split()
    #print(numofway)
    #input ways
    ways = []
    for _ in range(int(numofway)):
        reg = input().split()
        ways.append(reg)
        ways.append(reg[::-1])

    #count all ways we can arrive endpoint
    allways = []
    def countway(end:int, path:list):
        for index in ways:
            if path[-1] == index[0] and index[1] == end:
                allways.append(path+[index[1]])
            elif path[-1] == index[0] and index[1] not in path:
                countway(end,path+[index[1]])
    countway(end,list(start))

    #choose the ways which throw the point of restpoints
    allways = list(filter(lambda x: any(i in restpoints for i in x), allways))
    allways = sorted(allways, key=lambda x: len(x))
    #print(allways)
    if allways == []:
        print('NO')
    else:
        #for i in allways[0]: print(i,end=' ') if i in restpoints else None
        for i in restpoints: print(i,end=' ') if i in allways[0] else None
        
        print()
        print(*allways[0])

if __name__ == '__main__':
    main()