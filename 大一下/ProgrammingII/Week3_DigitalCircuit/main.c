#include <stdio.h>
#include <math.h>

void encode_10_str2(int output){
    char target[15]={'0'};
    for(int i=0;i<14;i++)
        if(output>=pow(2,13-i)){
            target[i]='1';
            output-=pow(2,13-i);
        }
        else target[i]='0';
    printf("%s\n",target);
}

int decode_str2_10(char input[11]){
    int target=0;
    for(int i=9;i>=0;i--) if(input[i]=='1') target += pow(2,9-i);
    //printf("%d\n",target);
    return target;
}

int CR(int N,int R){
    if(N==0||N==1) return R;
    else if(N%2==0) return CR(N/2,R+1);
    else return CR((N+1)/2,R+1);
}

int T(int num){
    int target=0;
    for(int i=0;i<=num;i++) target += CR(i,0);
    //printf("%d\n",target);
    return target;
}

int main(){
    char input[11]; int reg=0;
    while (1){
        scanf(" %s",&input);
        encode_10_str2(T(decode_str2_10(input)));
        scanf(" %d",&reg);
        if(reg==-1) break;

    }
    return 0;
}