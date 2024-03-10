def main():
    caves = {}
    ways = {}
    numofcave, start = input().split()
    for _ in range(int(numofcave)):
        reginput = list(map(int,input().split()))
        caves[reginput[0]] = reginput[1:]
    
    def countingmostgold(bag:int,start:int,path:str)->int:
        
        if str(start) in path.split() or (caves[start][1]==0 and caves[start][2]==0):
            ways[bag] = path
            return 0
        else:
            bag += caves[start][0]
            countingmostgold(bag,caves[start][1],path+' '+str(start))
            countingmostgold(bag,caves[start][2],path+' '+str(start))


    countingmostgold(0,int(start),'')
    ans = sorted(ways.keys(),key=lambda x:x,reverse=True)
    print(ans[0])


if __name__ == '__main__':
    main()