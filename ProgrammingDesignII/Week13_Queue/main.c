#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s * next;
}node_t;

typedef node_t * nodep_t;

nodep_t pushQueue(nodep_t QueuePtr){
    nodep_t regNode = QueuePtr;
    nodep_t BottomNode = QueuePtr;

    while(BottomNode->data != -1){
        regNode = BottomNode;
        BottomNode = BottomNode->next;
    }
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    scanf("%d", &newNode->data);

    if(BottomNode == QueuePtr){
        newNode->next = QueuePtr;
        QueuePtr = newNode;
    }
    else{
        regNode->next = newNode;
        newNode->next = BottomNode;
    }
    return QueuePtr;
}

nodep_t popQueue(nodep_t QueuePtr){
    if(QueuePtr->data == -1) printf("Queue is empty\n");
    else{
        printf("%d\n", QueuePtr->data);
        nodep_t regNode = QueuePtr;
        QueuePtr = QueuePtr->next;
        free(regNode);
    }
    return QueuePtr;
}

void frontQueue(nodep_t QueuePtr){
    if(QueuePtr->data == -1) printf("Queue is empty\n");
    else printf("%d\n", QueuePtr->data);
}

nodep_t emptyQueue(nodep_t QueuePtr){
    if(QueuePtr->data == -1) printf("Queue is empty\n");
    else{
        while(QueuePtr->data != -1){
            nodep_t regNode = QueuePtr;
            QueuePtr = QueuePtr->next;
            free(regNode);
        }
    }
    return QueuePtr;
}

void printQueue(nodep_t QueuePtr){
    if(QueuePtr->data == -1) printf("Queue is empty\n");
    else{
        while(QueuePtr->data != -1){
            printf("%d\n", QueuePtr->data);
            QueuePtr = QueuePtr->next;
        }
    }
}


int main(){

    int NumofInstruction;
    scanf("%d", &NumofInstruction);

    node_t Bottom = {-1, NULL};
    nodep_t QueuePtr = &Bottom;

    for(int i=0; i<NumofInstruction;i++){
        char regStr[6];
        scanf("%s", regStr);
        if(strcmp(regStr, "push") == 0) QueuePtr = pushQueue(QueuePtr);
        else if(strcmp(regStr, "pop") == 0) QueuePtr = popQueue(QueuePtr);
        else if(strcmp(regStr, "front") == 0) frontQueue(QueuePtr);
        else if(strcmp(regStr, "empty") == 0) QueuePtr = emptyQueue(QueuePtr);
        else if(strcmp(regStr, "print") == 0) printQueue(QueuePtr);       
    }

    return 0;
}