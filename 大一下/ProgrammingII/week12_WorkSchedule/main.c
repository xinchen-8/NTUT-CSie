#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int machine;
    int hours;
}Process;

typedef struct {
    Process *Pptr;
    int pnum;
    int index;// start from 0, where scedule of arrangement 
    int lastclk;// depend on the last clock of last work
}Work;

int main(){

    //initial
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
    //

    //main
    //int *lineclockindex = (int *)calloc(Numofline, sizeof(int));// machine lines
    int *lineclockindex = (int *)malloc(Numofline*sizeof(int));// machine lines
    for(int i=0; i<Numofline; i++) lineclockindex[i] = 0;

    while(1){
        //for(int i=0; i<Numofline; i++) printf("machineLine: %d\n", lineclockindex[i]);
        //select
        int clockindex = 99999;
        int minindex_work = 0;

        int breakflag = 1;
        for(int i=0; i<NumofWork; i++){
            if(works[i].index < works[i].pnum){
                breakflag = 0;
                Process reg_process = works[i].Pptr[works[i].index];
                //printf("===============================\n");
                int time = (lineclockindex[reg_process.machine]>works[i].lastclk)? lineclockindex[reg_process.machine]+reg_process.hours:works[i].lastclk+reg_process.hours;
                //printf("compare time: %d\n", time);
                //printf("===============================\n");
                
                if(time < clockindex){// change
                    clockindex = time;
                    minindex_work = i;
                }
            }
        }
        if(breakflag) break;

        //do
        lineclockindex[works[minindex_work].Pptr[works[minindex_work].index].machine] = clockindex;
        works[minindex_work].lastclk = clockindex;
        //printf("change clock: %d\n", clockindex);
        works[minindex_work].index++;
        //
    }

    //output
    int count = 0;
    for(int i=0; i<NumofWork; i++) count += works[i].lastclk;
    printf("%d\n", count);


    free(lineclockindex);
    for(int i=0; i<NumofWork; i++) free(works[i].Pptr);
    free(works);
    return 0;
}