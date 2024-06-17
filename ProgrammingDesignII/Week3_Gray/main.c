#include <stdio.h>
#include <math.h>


void gray(int n,int k){
    //printf("%d %d %d\n",n,k,k<(2^(n-1)));
    if(n==1) printf("%d",k);
    else if(k < pow(2,n-1)){
        //printf("%d %d %d\n",n,k,k<(2^(n-1)));
        printf("0");
        gray(n-1,k);
    }
    else if(k >= pow(2,n-1)){
        printf("1");
        //printf("%d %d %d\n",n,k,k<(2^(n-1)));
        
        gray(n-1,pow(2,n)-1-k);
    }
}


int main(){
    int regn,regk = 0;

    while(1){
        scanf(" %d",&regn);
        if(regn==-1) break;

        scanf(" %d",&regk);
        gray(regn,regk);
        printf("\n");
    }

    return 0;
}