#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s * next;
}node_t;

typedef node_t * nodep_t;

nodep_t pushStack(nodep_t StackPtr){
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    scanf("%d", &newNode->data);
    newNode->next = StackPtr;
    StackPtr = newNode;
    return StackPtr;
}

nodep_t popStack(nodep_t StackPtr){
    if(StackPtr->data == -1) printf("Stack is empty\n");
    else{
        nodep_t regNode = StackPtr;
        StackPtr = StackPtr->next;
        printf("%d\n", regNode->data);
        free(regNode);
    }
    return StackPtr;
}

void topStack(nodep_t StackPtr){
    if(StackPtr->data == -1) printf("Stack is empty\n");
    else printf("%d\n", StackPtr->data);
}

nodep_t emptyStack(nodep_t StackPtr){
    if(StackPtr->data == -1) printf("Stack is empty\n");
    else{
        while(StackPtr->data != -1){
            nodep_t regNode = StackPtr;
            StackPtr = StackPtr->next;
            free(regNode);
        }
    }
    return StackPtr;
}

void printStack(nodep_t StackPtr){
    if(StackPtr->data == -1) printf("Stack is empty\n");
    else{
        while(StackPtr->data != -1){
            printf("%d\n", StackPtr->data);
            StackPtr = StackPtr->next;
        }
    }
}


int main(){

    int NumofInstruction;
    scanf("%d", &NumofInstruction);

    node_t Bottom = {-1, NULL};
    nodep_t StackPtr = &Bottom;

    for(int i=0; i<NumofInstruction;i++){
        char regStr[6];
        scanf("%s", regStr);
        if(strcmp(regStr, "push") == 0) StackPtr = pushStack(StackPtr);
        else if(strcmp(regStr, "pop") == 0) StackPtr = popStack(StackPtr);
        else if(strcmp(regStr, "top") == 0) topStack(StackPtr);
        else if(strcmp(regStr, "empty") == 0) StackPtr = emptyStack(StackPtr);
        else if(strcmp(regStr, "print") == 0) printStack(StackPtr);
        
    }

    return 0;
}