#include <stdio.h>
#include <string.h>

void carry(int *num, int size){
    for(int i=size-1;i>=0;i--){
        if(num[i]>9){
            num[i-1]+=num[i]/10;
            num[i]%=10;
        }
    }
}

void teninverse(int *num, int size){
    for(int i=0;i<size;i++) num[i]=9-num[i];
    num[size-1]+=1;
    num[0]=0;//sign
    carry(num, 101);
}

int transform(int *num, char *reg){
    int index=0, neg=(reg[0]=='-')? 1:0;
    reg[0]=(reg[0]=='-')? '0':reg[0];
    for(;index<100&&reg[index]!='\0';index++) NULL;
    for(int i=0;i<index;i++) num[100-i]=reg[index-i-1]-'0';
    if(neg) teninverse(num, 101);
    return neg;
}

void plus(int (*num)[101]){
    for(int i=0;i<101;i++) num[2][i]=num[0][i]+num[1][i];
    carry(num[2], 101);
}

void minus(int (*num)[101]){
    teninverse(num[1], 101);
    for(int i=0;i<101;i++) num[3][i]=num[0][i]+num[1][i];
    carry(num[3], 101);
    teninverse(num[1], 101);
}

void multiple(int (*num)[101], int *ans){
    for(int baseindex=100;baseindex>=0;baseindex--){
        for(int i=100;i>=0;i--) ans[i+baseindex]+=num[0][baseindex]*num[1][i];
    }
    carry(ans, 201);
}

void output(int *num, int neglogic, int size){
    if(neglogic){
        if(size<200) teninverse(num, size);
        printf("-");
    }
    int button=0;
    for(int i=1;i<size;i++){
        if(!button && num[i]!=0) button=1;
        if(button) printf("%d",num[i]);
    }
    if(!button) printf("0");
    printf("\n");
}

int main(){
    int number[4][101], neg[2], answer[201];//sign, numbers...
    for(int i=0;i<3;i++) memset(number[i], 0, 101*sizeof(int));
    memset(answer, 0, 201*sizeof(int));

    char regstring[100];//input
    scanf("%s", regstring);
    neg[0] = transform(number[0],regstring);
    scanf("%s", regstring);
    neg[1] = transform(number[1],regstring);

    plus(number); 
    output(number[2], number[2][1], 101);
    
    minus(number);
    output(number[3], number[3][1], 101);

    for(int i=0;i<2;i++) if(neg[i]) teninverse(number[i], 101);

    //for(int i=0;i<101;i++) printf("%d",number[0][i]);
    //printf("\n");
    
    //for(int i=0;i<101;i++) printf("%d",number[1][i]);
    //printf("\n");
    
    //for(int i=0;i<101;i++) printf("%d",number[3][i]);
    //printf("\n");

    multiple(number, answer);
    output(answer, neg[0]^neg[1], 201);

    return 0;
}