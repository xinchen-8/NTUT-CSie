#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void sorting(int *scores, int *bill, int len){
    for(int i=1;i<len;i++){
        int j=i, sreg=scores[i], breg=bill[i];
        for(;j>=1 && sreg<scores[j-1];j--){
            scores[j] = scores[j-1];
            bill[j] = bill[j-1];
        }
        scores[j] = sreg;
        bill[j] = breg;
    }
}

int weight(int *list, int num){
    int weight=0, index=0;
    for(int i=num-1;i>=0;i--) weight += pow(10,i)*list[index++];
    return weight;
}

void compare_allsame(int *list, int nowi, int pastk, int num){
    int button=1;
    for(int i=0;i<num;i++) if(list[nowi*num+i]!=list[pastk*num+i]) button = 0;
    if(button) for(int i=0;i<num;i++) list[nowi*num+i] = -1;
}

void compare_partsame(int *list, int num){
    int button=0;
    for(int i=0;i<num;i++) for(int j=i-1;j>=0;j--) if(list[i]==list[j]) button = 1;
    if(button) for(int i=0;i<num;i++) list[i] = -1;
}

int main(){
    int num, reg[21];
    memset(reg, -1, sizeof(int)*21);
    scanf("%d",&num);
    
    //input
    int index=-1;
    do{
        scanf(" %d",&reg[++index]);    
    }while(reg[index]!=-1);

    //make list and counting score
    int *list = malloc((index-num+1)*num*sizeof(int));
    int count=0;
    for(int i=0;i<index-num+1;i++){
        for(int j=0;j<num;j++){
            list[i*num+j] = reg[i+j];
        }
        compare_partsame(&list[i*num], num);
        if(list[i*num]>=0) count++;
    }
    printf("%d\n", count);

    int *score = malloc((index-num+1)*sizeof(int));
    int *bill = malloc((index-num+1)*sizeof(int));
    for(int i=0;i<index-num+1;i++){
        bill[i] = i;
        for(int j=i-1;j>=0;j--) compare_allsame(list,i,j, num);
        score[i] = weight(&list[i*num], num);
    }
    sorting(score, bill, index-num+1);
    for(int i=0;i<index-num+1;i++){
        if(score[i]>=0){
            for(int j=0;j<num;j++) printf("%d ",list[bill[i]*num+j]);
            printf("\n");
        }
        else continue;
    }

    free(bill);   
    free(list);
    free(score);
    return 0;
}