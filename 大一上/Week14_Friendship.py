member = int(input())
membernetwork = {}
networkAtoB = []

#membernetwork[startname+endname] = relationpoint
inputlist = input().split()
while(inputlist[0] != '-1'):
    membernetwork[inputlist[0]+inputlist[1]] = int(inputlist[2])
    inputlist = input().split()

for key, value in membernetwork.items():
    membernetwork[key] = min(membernetwork.get(key[::-1],value),value)
    membernetwork[key[::-1]] = membernetwork[key]
#print(membernetwork)

#finding function: find the network
def finding(path:str, endname:str, lastpoint:int):
        
        reg_membernetwork = []
        for key, value in membernetwork.items():
            if key[0] == path[-1]:
                reg_membernetwork.append([key[1], value])
        #print(path,lastpoint,reg_membernetwork)

        if len(reg_membernetwork)==0: return 1
    
        for index in reg_membernetwork:
                     
            if index[0] == endname:
                networkAtoB.append([path+' '+index[0], lastpoint+index[1]])
            
            elif index[0] not in path:
                finding(path+' '+index[0], endname, lastpoint+index[1])


finding('A','B',0)
#print(networkAtoB[0][0])

sortnetwork = sorted(networkAtoB,key=lambda x: len(x[0]))
print((len(sortnetwork[0][0])+1)//2-1)
print(sortnetwork[0][0])
sortnetwork = sorted(networkAtoB,key=lambda x: x[1],reverse=True)
print(sortnetwork[0][1])
print(sortnetwork[0][0])
