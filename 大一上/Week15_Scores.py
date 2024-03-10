
class Data:
    def __init__(self,courseid,semester,studentid,score) -> None:
        self.courseid = courseid
        self.semester = semester
        self.studentid = studentid
        self.score = score

class Table:
    def __init__(self) -> None:
        self.datalist = []
        self.index_record = {'academicyear':[],'inyear':[],'apartment':[]}#待處理A
    
    def append(self,data:Data):
        self.datalist.append(data)
        self.datalist = sorted(self.datalist,key=lambda x:int(x.studentid))

        self.index_record['academicyear'].append(data.semester[:-1])
        self.index_record['inyear'].append(data.studentid[:3])
        self.index_record['apartment'].append(data.studentid[3:6])

    def partone_dict(self)->dict:#{apartment:{inyear:(academicyear:{studentid:[scores,rank,refund,credits,numofsubjects])}}
        regdict1 = {}
        #turn to format
        for object in self.datalist:
            
            if not regdict1.get(object.studentid[3:6],0):
                regdict1[object.studentid[3:6]] = {}

            if not regdict1[object.studentid[3:6]].get(object.studentid[:3],0):
                regdict1[object.studentid[3:6]][object.studentid[:3]] = {}

            if not regdict1[object.studentid[3:6]][object.studentid[:3]].get(object.semester[:-1],0):
                regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]] = {}

            if not regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]].get(object.studentid,0):
                regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]][object.studentid] = [object.score*int(object.courseid[-1]),0,0,int(object.courseid[-1]),1]
            else:
                register = regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]][object.studentid]
                if object.score!=-1:
                    regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]][object.studentid] = [x+y for x,y in zip(register,[object.score*int(object.courseid[-1]),0,0,int(object.courseid[-1]),1])]
                else:
                    regdict1[object.studentid[3:6]][object.studentid[:3]][object.semester[:-1]][object.studentid] = [x+y for x,y in zip(register,[0,0,1,0,1])]
        #calculate
        for apartment, i in regdict1.items():
            for inyear, j in i.items():
                for academicyear, k in j.items():
                    for studentid, l in k.items():

                        regdict1[apartment][inyear][academicyear][studentid] = [int(l[0]/l[3]),l[1],int(l[2]*100/l[4])]
        return regdict1            

    def parttwo_dict(self):#{courseid:{academicyear:{studentid:[score1,score2,sumscore,credit,haverefund:bool]}}}
        regdict1 = {}
        #turn to format
        for object in self.datalist:
            
            if not regdict1.get(object.courseid,0):
                regdict1[object.courseid] = {}

            if not regdict1[object.courseid].get(object.semester[:-1],0):
                regdict1[object.courseid][object.semester[:-1]] = {}

            if not regdict1[object.courseid][object.semester[:-1]].get(object.studentid,0):
                if object.score == -1:
                    regdict1[object.courseid][object.semester[:-1]][object.studentid] = [-1,-1,-1,-1,1]
                elif object.semester[-1]=='1':
                    regdict1[object.courseid][object.semester[:-1]][object.studentid] = [object.score,-1,object.score*int(object.semester[-1]),int(object.semester[-1]),0]
                elif object.semester[-1]=='2':
                    regdict1[object.courseid][object.semester[:-1]][object.studentid] = [-1,object.score,object.score*int(object.semester[-1]),int(object.semester[-1]),0]
            else:
                register = regdict1[object.courseid][object.semester[:-1]][object.studentid]
                if object.score == -1:
                    regdict1[object.courseid][object.semester[:-1]][object.studentid] = [x+y for x,y in zip(register,[object.score,-1,object.score*int(object.semester[-1]),0])]            
                elif object.semester[-1]=='1':
                    regdict1[object.courseid][object.semester[:-1]][object.studentid] = [x+y for x,y in zip(register,[-1,object.score,object.score*int(object.semester[-1]),0])]
                else:
                    regdict1[object.courseid][object.semester[:-1]][object.studentid][4] = 1
        #calculate
        for course, i in regdict1.items():
            for academicyear, j in i.items():
                for studentid, data in j.items():
                    regdict1[course][academicyear][studentid] = [data[0],data[1],int(data[2]/data[3])if data[3]!=0 else 0,data[4]]
        return regdict1

    def partthree_dict(self,search):
        regdict1 = {}; regdict2 = {}
        #turn to format
        for object in self.datalist:
            if object.courseid ==search:
                regdict1[object.studentid] = max(regdict1.get(object.studentid,0),object.score)
                regdict2[object.studentid[3:6]] = regdict2.get(object.studentid[3:6],0) + 1
        regdict1 = dict(sorted(regdict1.items(),key=lambda x:x[1],reverse=True))
        regdict2 = dict(sorted(regdict2.items(),key=lambda x:x[1],reverse=True))
        #print(regdict1)
        print(f'{list(regdict1.keys())[0]} {list(regdict1.keys())[1]} {list(regdict2.keys())[0]} {list(regdict2.keys())[1] if len(regdict2)>=2 else ""}')


def rankpercentage(rank:int,people:int,pastpoint:int=0,count:int=1)->int:
    range = int(count*people/100+0.99)-pastpoint
    if rank-range<=0: return count
    else: return rankpercentage(rank-range,people,pastpoint+range,count+1)
    

def main():

    datatable = Table()
    dict1 = {}
    dict2 = ()
    dict3 = {}

    for _ in range(int(input())):
        courseid, semester, numofstudents = input().split()

        for _ in range(int(numofstudents)):
            regB = input().split() #studentid score test
            
            if regB[1] =='w': score = -1
            elif courseid[:-1]=='101' or courseid[:-1]=='201': score = int(int(regB[1])*0.7+int(regB[2])*0.3+0.99)
            else: score = int(regB[1])
            
            data = Data(courseid,semester,regB[0],score)
            datatable.append(data)
    part3search = input()

    #part1
    dict1 = datatable.partone_dict()
    for i,j in sorted(dict1.items(),key=lambda x:int(x[0])):
        for k,l in sorted(dict(j).items(),key=lambda x:int(x[0])):
            for m,n in sorted(dict(l).items(),key=lambda x:int(x[0])):
                print(f'{i} {k} {m}')
                count = 1
                for o,p in sorted(dict(n).items(),key=lambda x:int(x[1][0]),reverse=True):
                    print(f'{o} {p[0]} {rankpercentage(count,len(n))}% {p[2]}%')
                    count += 1
                    if count>3: break

    #part2
    dict2 = datatable.parttwo_dict()
    for i,j in sorted(dict2.items(),key=lambda x:int(x[0])):
        for k,l in sorted(dict(j).items(),key=lambda x:int(x[0])):
            refundtime = 0; maxscore = 0; minscore = 100; totalscore = [0,0]
            for m,n in sorted(dict(l).items(),key=lambda x:int(x[0])):
                if n[-1]: refundtime += n[-1]
                maxscore = max(maxscore,n[0] if n[0]!=-1 else 0,n[1] if n[1]!=-1 else 0)
                minscore = min(minscore,n[0] if n[0]!=-1 else 100,n[1] if n[1]!=-1 else 100)
                if n[0]!=-1: totalscore = [x+y for x,y in zip(totalscore,[n[0],1])]
                if n[1]!=-1: totalscore = [x+y for x,y in zip(totalscore,[n[1],1])]
            print(f'{i} {k}')
            print(f'{maxscore} {int(totalscore[0]/totalscore[1])} {minscore} {int(refundtime*100/len(l))}%')
            count = 1
            for m,n in sorted(dict(l).items(),key=lambda x:int(x[1][2]),reverse=True):
                print(f'{m} {n[2]} {rankpercentage(count,len(l))}%')
                count += 1
                if count>3: break
    
    #part3
    datatable.partthree_dict(part3search)



if __name__ =='__main__':
    main()