def main():
    title = input()
    elements = input().split()
    DNA = input()
    outputbox = []

    while len(DNA) != 0:
        titleindex = (DNA.find(title)+4) if DNA.find(title)!=-1 else -1
        endindex = sorted(filter(lambda x: x!=-1,list(map(lambda x: DNA.find(x,titleindex), elements))))
        if titleindex==-1 or len(endindex)==0: break
        
        while DNA[titleindex:endindex[0]].find(title)!=-1:
            titleindex = (DNA.find(title)+4)
            endindex = sorted(filter(lambda x: x!=-1 and x>titleindex,list(map(lambda x: DNA.find(x), elements))))
        outputbox.append(DNA[titleindex:endindex[0]])
        DNA = DNA[endindex[0]+3:]

    if len(outputbox)==0: print('No gene')
    else:
        outputbox.sort()
        outputbox.sort(key=lambda x:len(x))
        print(*outputbox,sep='\n')

if __name__ == '__main__': main()