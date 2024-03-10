#include <stdio.h>
#include <math.h>

//idea by easn
int turnint(char *token,int index){
    int record = 0;
    //printf("A::%c\n",token[index]);
    while('0'<=(int)*(token+index)&&'9'>=(int)*(token+index)){
        record = record*10+(int)*(token+index)-'0';
        index++;
    }
    return record;
}

void input(char str[15], int *frac){
    //idea by easn
    int index = (str[0]=='-')?1:0;
    frac[0] *= (str[0]=='-')?-1:1;

    for(int i=1;i<4;i++){
        frac[i] = turnint(str,index);
        if(frac[i]==0) break;
        index += log10(frac[i])+1+1;//important!!!
        if(str[index-1]=='\0') break;
    }
    //have integer case:[neg,int,up,down]
    if(frac[3]==-1){
        frac[3] = frac[2];
        frac[2] = frac[1];
        frac[1] = 0;
    }
    //no integer case:[neg,0,up,down]
}

void openinteger(int *frac){
    frac[2] = frac[0]*(frac[1]*frac[3] + frac[2]);
    frac[1] = 0;
    frac[0] = 1;
    //printf("%d %d %d %d\n",frac[0],frac[1],frac[2],frac[3]);
}

int lookforcommon(int a,int b){
    if(b==0) return a;
    else if(a>b) return lookforcommon(b,a%b);
    else return lookforcommon(a,b%a);
}

void reduce(int *frac){

    frac[0] = (frac[2]<0)?-1:1;
    frac[2] = abs(frac[2]);
    if(frac[2]!=0){
        int common = lookforcommon(frac[2],frac[3]);
        frac[2] /= common;
        frac[3] /= common;
    }
    
    while(frac[2]>=frac[3]){
        frac[2] -= frac[3];
        frac[1]++;
    }
    //printf("%d %d %d %d\n",frac[0],frac[1],frac[2],frac[3]);

}

void plus(int *frac1,int *frac2){
    frac1[2] = frac1[2]*frac2[3]+frac2[2]*frac1[3];
    frac1[3] *= frac2[3];
    reduce(frac1);
}

void sub(int *frac1,int *frac2){
    frac1[2] = frac1[2]*frac2[3]-frac2[2]*frac1[3];
    frac1[3] *= frac2[3];
    reduce(frac1);
}

void multi(int *frac1,int *frac2){
    frac1[2] *= frac2[2];
    frac1[3] *= frac2[3];
    reduce(frac1);
}

void divi(int *frac1,int *frac2){
    frac1[2] *= frac2[3];
    frac1[3] *= frac2[2];
    if(frac1[3]<0){
        frac1[3] = abs(frac1[3]);
        frac1[2] *= -1;
    }
    reduce(frac1);
}

int main(){
    char reg1[15]={'0'},reg2[15]={'0'};
    char sign='0',button='y';
    
    while(button=='y'){
        int frac1[4]={1,0,0,-1};
        int frac2[4]={1,0,0,-1};

        scanf(" %s",&reg1);
        scanf(" %c",&sign);
        scanf(" %s",&reg2);

        input(reg1,frac1);
        input(reg2,frac2);

        openinteger(frac1);
        openinteger(frac2);
        //protect from "over 0" case
        if(frac1[3]==0||frac2[2]==0||frac2[3]==0||(sign=='/'&&frac2[1]==0&&frac2[2]==0)) printf("error\n");
        
        else{
            switch (sign)//answer in frame1
            {
            case '+':
                plus(frac1,frac2);
                break;
            case '-':
                sub(frac1,frac2);
                break;
            case '*':
                multi(frac1,frac2);
                break;
            case '/':
                divi(frac1,frac2);
                break;
            
            }
            //printf("\n%d %d %d %d\n",frame1.integer,frame1.up,frame1.down,frame1.neg_button);
            if(frac1[0]==-1 && (frac1[1]!=0||frac1[2]!=0))printf("-");
            if(frac1[1]!=0){
                printf("%d",frac1[1]);
                if(frac1[2]!=0)printf("(%d/%d)\n",frac1[2],frac1[3]);
                else printf("\n");
            }
            else if(frac1[2]!=0)printf("%d/%d\n",frac1[2],frac1[3]);
            else printf("0\n");
        }

        //printf("%d %d %d %d",frame2.integer,frame2.up,frame2.down,frame2.neg_button);
        scanf(" %c",&button);
    }
    return 0;
}