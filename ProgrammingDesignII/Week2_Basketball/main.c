#include <stdio.h>

int turnint(char team){
    switch(team){
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
    }
}

int main(){

    int win_times[3] = {0};
    int scores[3] = {0};//A B C
    int regi[2] = {0};
    int sum[2] = {0};
    char regc[3] = {'0'};

    int num = 0;
    scanf("%d",&num);

    for(int i=0;i<num;i++){
        scanf(" %c %c",&regc[0],&regc[1]);
        //printf("%s\n",regc);
        for(int j=0;j<4;j++){
            scanf("%d %d",&regi[0],&regi[1]);
            //printf("%d %d\n",regi[0],regi[1]);
            sum[0] += regi[0];
            sum[1] += regi[1];
        }
        
        if(sum[0]>sum[1]) win_times[turnint(regc[0])] += 1;
        else win_times[turnint(regc[1])] += 1;

        scores[turnint(regc[0])] += sum[0];
        scores[turnint(regc[1])] += sum[1];
        sum[0] = 0;
        sum[1] = 0;
    }
    //printf("%d %d %d",scores[0],scores[1],scores[2]);

    if(win_times[0]>win_times[1]&&win_times[0]>win_times[2]) printf("A\n%d",scores[0]);
    else if(win_times[1]>win_times[0]&&win_times[1]>win_times[2]) printf("B\n%d",scores[1]);
    else printf("C\n%d",scores[2]);

    return 0;
}