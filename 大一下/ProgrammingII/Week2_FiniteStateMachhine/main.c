#include <stdio.h>

int judge_var_str(char string[50],int index){
    if(index==0){
        if((string[0]<='Z' && string[0]>='A')||(string[0]<='z' && string[0]>='a')||string[0]=='_') return judge_var_str(string,1);
        else return 4;
    }
    else if((string[index]<='Z' && string[index]>='A')||(string[index]<='z' && string[index]>='a')||string[index]=='_'||(string[index]<='9' && string[index]>='0')) return judge_var_str(string,++index);
    else if(string[index]=='\0' && index<=10)return 3;
    else return 4;
}

int judge_int_float(char string[50],int index,int point_button){
    if(index==0){
        if(string[index]=='0' && string[1]=='\0') return 1;
        else if(string[index]=='-' && string[1]=='0' && string[2]=='\0') return 4;
        else if(string[index]=='-') return judge_int_float(string,1,0);
        else if(string[1]=='.' && string[2]!='\0') return judge_int_float(string,2,1);
        else if(string[index]<='9' && string[index]>='1') return judge_int_float(string,1,0);
        else return judge_var_str(string,0);
    }
    else if(string[index]=='.' && string[index+1]!='\0' && !point_button) return judge_int_float(string,++index,1);
    else if(string[index]<='9' && string[index]>='0') return judge_int_float(string,++index,point_button);
    else if(string[index]=='\0'){
        if(point_button) return 2;
        else return 1;
    }
    else return judge_var_str(string,0);
}

int main(){

    int num = 0;
    scanf("%d",&num);

    //input
    char reg[num][50];
    for(int i=0;i<num;i++){
        scanf("%s",& reg[i]);
    }

    //main
    for(int i=0;i<num;i++){
        switch (judge_int_float(reg[i],0,0)){
        
        case 1:
            printf("integer\n");
            break;
        
        case 2:
            printf("float\n");
            break;
        
        case 3:
            printf("variable\n");
            break;
        
        default:
            printf("string\n");
            break;
        }
    }

    return 0;
}