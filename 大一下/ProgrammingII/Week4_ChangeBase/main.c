#include <stdio.h>
#include <string.h>
#include <math.h>

int turn10base(char *str,int base){
    int total = 0;
    for(int i=0;i<strlen(str);i++){
        if('9'>=str[i] && str[i]>='0') total += (str[i]-'0') * pow(base,strlen(str)-1-i);
        else if('Z'>=str[i] && str[i]>='A') total += (str[i]-'A'+10) * pow(base,strlen(str)-1-i);
    }
    //printf("%d\n",total);
    return total;
}

void changebase(int pasttotal,int base, char *change_str){
    int index = 0;

    while(1){
        int a = pasttotal % base;
        pasttotal /= base;
        if(0<=a && a<=9) change_str[index] = a+'0';
        else change_str[index] = 'A'+a-10;

        //printf("%s\n",change_str);
        if(pasttotal==0) break;
        index++;
    }
}

int main(){
    char str[11];
    int base = 0;
    int change_base = 0;
    char change_str[100];
    
    scanf("%d",&base);
    scanf("%s",str);
    scanf("%d",&change_base);


    changebase(turn10base(str,base),change_base,change_str);
    for(int i=strlen(change_str)-1;i>=0;i--) printf("%c",change_str[i]);

    return 0;
}