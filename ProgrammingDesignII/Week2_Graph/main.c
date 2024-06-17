#include <stdio.h>

void node1(int m){
    for(int row=0;row<m;row++){
        for(int i=0;i<m-row-1;i++){
            printf("#");
        }
        for(int j=0;j<row;j++){
            printf("*%c",65+(row-1)%3);
        }
        printf("*");
        for(int k=0;k<m-row-1;k++){
            printf("#");
        }
        printf("\n");
    }
}

void node2(int m){
    for(int row=1;row<m+1;row++){
        for(int i=0;i<row;i++){
            printf("%d",i+1);
        }
        for(int j=0;j<m-row+1;j++){
            printf("**");
        }
        for(int k=row;k>0;k--){
            printf("%d",k);
        }
        printf("\n");
    }
}


int main(){

    int m,n = 0;
    scanf("%d",&n);
    scanf("%d",&m);

    if(m>9||m<2) printf("error");
    else{
        switch(n){
            case 1:
                node1(m);
                break;

            case 2:
                node2(m);
                break;

            default:
                printf("error");
                break;
        }
    }

    return 0;
}