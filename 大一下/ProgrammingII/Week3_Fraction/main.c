#include <stdio.h>
#include <math.h>

struct fraction{
    int integer;
    int up,down;
    int neg_button;
};

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

int lookforcommon(int a,int b){
    if(b==0) return a;
    else if(a>b) return lookforcommon(b,a%b);
    else return lookforcommon(a,b%a);
}

void reduce(struct fraction *frame){

    frame->neg_button *= (frame->up<0)?-1:1;
    frame->up = abs(frame->up);
    
    int common = lookforcommon(frame->down,frame->up);
    frame->down /= common;
    frame->up /= common;
    
    while(frame->up>=frame->down){
        frame->up -= frame->down;
        frame->integer += 1;
    }
}

void openinteger(struct fraction *frame){
    frame->up += (frame->integer)*(frame->down);
    frame->integer = 0;
}

void transform(char str[15],struct fraction *frame){
    frame->neg_button = 1;
    frame->integer = 0;
    frame->up = 0;
    frame->down = 0;
    
    //idea by easn
    int reg[3];
    int index=(str[0]=='-')?1:0;
    for(int i=0;i<3;i++){
        reg[i] = turnint(str,index);
        if(reg[i]==0) break;
        index += log10(reg[i])+1+1;//important!!!
        //printf("B::%c\n",str[index-1]);
        if(str[index-1]=='\0') break;
    }
    
    if (reg[2]==0){
        frame->neg_button = (str[0]=='-')?-1:1;
        frame->integer = 0;
        frame->up = reg[0];
        frame->down = reg[1];

    }
    else{
        frame->neg_button = (str[0]=='-')?-1:1;
        frame->integer = reg[0];
        frame->up = reg[1];
        frame->down = reg[2];
    }
}

void plus(struct fraction *frame1,struct fraction *frame2){
    frame1->down *= frame2->down;
    frame1->up *= frame2->down * frame1->neg_button;
    frame1->neg_button = 1;//important!!!
    //frame2->down *= frame1->down;
    frame2->up *= (frame1->down/frame2->down) * frame2->neg_button;
    frame1->up += frame2->up;
    reduce(frame1);
}

void sub(struct fraction *frame1,struct fraction *frame2){
    frame1->down *= frame2->down;
    frame1->up *= frame2->down * frame1->neg_button;
    frame1->neg_button = 1;//important!!!
    //frame2->down *= frame1->down;
    frame2->up *= (frame1->down/frame2->down) * frame2->neg_button;
    frame1->up -= frame2->up;
    reduce(frame1);
}

void multi(struct fraction *frame1,struct fraction *frame2){
    frame1->up *= frame2->up;
    frame1->down *= frame2->down;
    frame1->neg_button *= frame2->neg_button;
    reduce(frame1);
}

void divi(struct fraction *frame1,struct fraction *frame2){
    frame1->up *= frame2->down;
    frame1->down *= frame2->up;
    frame1->neg_button *= frame2->neg_button;
    reduce(frame1);

}

int main(){
    struct fraction frame1,frame2;
    char reg1[15]={'0'},reg2[15]={'0'};
    char sign='0',button='y';

    
    while(button=='y'){
        scanf(" %s",&reg1);//transform
        transform(reg1,&frame1);
        scanf(" %c",&sign);//do
        scanf(" %s",&reg2);//transform
        transform(reg2,&frame2);

        if(frame1.down==0||frame2.down==0||(sign=='/'&&frame2.up==0&&frame2.integer==0)) printf("error\n");
        else{
            openinteger(&frame1);
            openinteger(&frame2);

            switch (sign)//answer in frame1
            {
            case '+':
                plus(&frame1,&frame2);
                break;
            case '-':
                sub(&frame1,&frame2);
                break;
            case '*':
                multi(&frame1,&frame2);
                break;
            case '/':
                divi(&frame1,&frame2);
                break;
            
            }
            //printf("\n%d %d %d %d\n",frame1.integer,frame1.up,frame1.down,frame1.neg_button);
            if(frame1.neg_button==-1)printf("-");
            if(frame1.integer!=0){
                printf("%d",frame1.integer);
                if(frame1.up!=0)printf("(%d/%d)\n",frame1.up,frame1.down);
                else printf("\n");
            }
            else if(frame1.up!=0)printf("%d/%d\n",frame1.up,frame1.down);
            else printf("0\n");
        }

        //printf("%d %d %d %d",frame2.integer,frame2.up,frame2.down,frame2.neg_button);
        scanf(" %c",&button);
    }
    return 0;
}