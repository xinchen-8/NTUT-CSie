#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int machine;
    int hours;
}Process;

typedef struct {
    Process *Pptr;
    int pnum;
    int index;
    int lastclk;
}Work;

int main(){

    int Numofline, NumofWork;
    scanf("%d %d", &Numofline, &NumofWork);

    Work *works = (Work *)malloc(sizeof(Work)*NumofWork);
    for(int i=0; i<NumofWork; i++){
        
        int NumofProcess;
        scanf("%d", &NumofProcess); 
        works[i].Pptr = (Process *)malloc(sizeof(Process)*NumofProcess);
        for(int j=0; j<NumofProcess; j++) scanf("%d %d", &works[i].Pptr[j].machine, &works[i].Pptr[j].hours);
        
        works[i].pnum = NumofProcess;
        works[i].index = 0;
        works[i].lastclk = 0;
    }

    int *lineclockindex = (int *)calloc(Numofline, sizeof(int));

    while(1){
        
        int clockindex = 99999;
        int minindex_work = 0;

        int breakflag = 1;
        for(int i=0; i<NumofWork; i++){
            if(works[i].index < works[i].pnum){
                breakflag = 0;
                Process reg_process = works[i].Pptr[works[i].index];
                int time = (lineclockindex[reg_process.machine]>works[i].lastclk)? lineclockindex[reg_process.machine]+reg_process.hours:works[i].lastclk+reg_process.hours;
                
                if(time < clockindex){
                    clockindex = time;
                    minindex_work = i;
                }
            }
        }
        if(breakflag) break;

        lineclockindex[works[minindex_work].Pptr[works[minindex_work].index].machine] = clockindex;
        works[minindex_work].lastclk = clockindex;
        works[minindex_work].index++;
        
    }

    int count = 0;
    for(int i=0; i<NumofWork; i++) count += works[i].lastclk;
    printf("%d\n", count);


    free(lineclockindex);
    for(int i=0; i<NumofWork; i++) free(works[i].Pptr);
    free(works);
    return 0;
}