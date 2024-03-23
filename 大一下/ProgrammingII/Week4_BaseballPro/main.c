#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

void insertsort(int *t_arr, int reff[9]){
    int temp = reff[2];
    for(int index=1;index<9;index++){
        int j=index-1;
        while(j>=0 && temp>reff[j]){
            reff[j+1] = reff[j];
            t_arr[j+1] = t_arr[j];
            j-=1;
        }
        reff[j+1] = temp;
        t_arr[j+1] = temp;
    }
}

void runbase(int *base,int *score, int number){
    for(int i=3;i>0;--){
        base[i] = base[i-1];
        score[base[i]]++;
    }
    base[0] = number;
    score[number]++;
}

int main(){
    
    int blow[9][5];
    int run_scroe[9];
    int blow_scroe[9];
    int base[4];
    int target = 0;
    int count = 0;

    memset(blow, 0, sizeof(blow));
    memset(run_score, 0, sizeof(score));
    memset(base, 0, sizeof(base));

    int buff = 0;
    for(int i=0;i<9;i++){
        scanf(" %d",&buff);
        for(int j=0;j<buff;j++){
            scanf(" %d",&blow[i][j]);
            if(blow[i][j]=='H') blow[i][j]=4;
        }
    }
    scanf(" %d",&target);

    int button = 0;
    for(int j=0;j<5;j++){
        for(int i=0;i<9;i++){
            if(!blow[i][j]){
                count++;
                if(count%3==0) memset(base, 0, sizeof(base));
                if(count==target){
                    button = 1;
                    break;
                }
                continue;
            }
            else{
                blow_scroe[j] += blow[i][j];
                for(int k=0;k<blow[i][j];i++) runbase(base,run_score,j);
            }
        }
        if(button) break;
    }

    int tag[9];
    for(int i=0;i<9;i++)tag[i]=i;
    insertsort(tag,blow_scroe);
    insertsort(tag,run_scroe);
    




    return 0;
}