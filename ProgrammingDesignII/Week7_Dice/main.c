#include <stdio.h>
#include <stdlib.h>

typedef struct dice{
    int dotnum;
    int top, down, left, right;
}diceptr;

void rotate_up(diceptr *ptr){
    ptr->top = ptr->dotnum;
    ptr->dotnum = ptr->down;
    ptr->down = 7-ptr->top;
}

void rotate_down(diceptr *ptr){
    ptr->down = ptr->dotnum;
    ptr->dotnum = ptr->top;
    ptr->top = 7-ptr->down;
}

void rotate_left(diceptr *ptr){
    ptr->left = ptr->dotnum;
    ptr->dotnum = ptr->right;
    ptr->right = 7-ptr->left;
}

void rotate_right(diceptr *ptr){
    ptr->right = ptr->dotnum;
    ptr->dotnum = ptr->left;
    ptr->left = 7-ptr->right;
}

int main(){
    //initial set
    diceptr *ptr = malloc(4*sizeof(diceptr));
    for(int i=0;i<4;i++){
        (ptr+i)->top = 3;
        (ptr+i)->down = 4;
        (ptr+i)->dotnum = 1;
        (ptr+i)->left = 5;
        (ptr+i)->right = 2;
    }
    void (*method[4])(diceptr*);
    method[0] = rotate_down;
    method[1] = rotate_up;
    method[2] = rotate_right;
    method[3] = rotate_left;

    //main
    int num, reg[4];
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &reg[j]);
            method[reg[j]-1](ptr+j);
        }
    }

    //count
    int score = 0, button = 1;
    int *counts = (int*)calloc(6,sizeof(int));
    for(int i=0;i<4;i++) counts[(ptr+i)->dotnum-1]++;
    //for(int i=0;i<6;i++) printf("%d",counts[i]);
    for(int i=0;i<6;i++){
        if(counts[i]==4){
            printf("18\n");
            button = 0;
            break;
        }
        if(counts[i]==2){
            int button2 = 1;
            for(int j=i+1;j<6;j++){
                if(counts[j]==2){
                    button2 = 0;
                    score = (j+1)*2;
                }
            }
            if(button2){
                for(int j=0;j<6;j++) if(counts[j]==1) score += j+1;
            }
        }
    }
    if(button) printf("%d\n", score);
    free(counts);
    free(ptr);
    return 0;
}