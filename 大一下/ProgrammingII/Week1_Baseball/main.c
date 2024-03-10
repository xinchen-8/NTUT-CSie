#include <stdio.h>

int running(int time,int run,int *base){

    if(time!=0){
        *(base+3) += *(base+2);
        *(base+2) = *(base+1);
        *(base+1) = *(base);
        *(base) = run;

        running(time-1,0,base);
    }
    else if(run==1){
        return 1;   //for clear flag
    }
    else return 0;
}

void clear(int *clearflag,int *base){
    *clearflag = 0;
    *base = *(base+1) = *(base+2) = 0;
}

int main(){

    int base_stack[4] = {0,0,0,0};
    int reg = 0, clearflag = 0;


    scanf("%d",&reg);
    clearflag += running(reg,1,base_stack);

    scanf("%d",&reg);
    clearflag += running(reg,1,base_stack);
    
    scanf("%d",&reg);
    clearflag += running(reg,1,base_stack);

    if (clearflag==3) clear(&clearflag,base_stack);
    scanf("%d",&reg);
    clearflag += running(reg,1,base_stack);

    if (clearflag==3) clear(&clearflag,base_stack);
    scanf("%d",&reg);
    clearflag += running(reg,1,base_stack);

    if (clearflag==3) clear(&clearflag,base_stack);
    printf("%d\n%d %d %d",base_stack[3], base_stack[0], base_stack[1], base_stack[2]);
    return 0;
}