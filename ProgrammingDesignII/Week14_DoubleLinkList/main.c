#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NumofMethods 8

typedef struct dnode_s {
    int data;
    struct dnode_s * front;
    struct dnode_s * back;
}node_t;

typedef node_t * nodep_t;

nodep_t addFront(nodep_t nodeptr, int n, int none){
    nodep_t newnode = (nodep_t)malloc(sizeof(node_t));
    newnode->back = NULL;
    newnode->front = NULL;

    if(nodeptr == NULL) newnode->data = n;
    else{
        for(int i=0; nodeptr->front!=NULL ; i++) nodeptr = nodeptr->front;
        newnode->back = nodeptr;
        newnode->data = n;
        nodeptr->front = newnode;
    }
    return newnode;
}

nodep_t addBack(nodep_t nodeptr, int n, int none){
    nodep_t newnode = (nodep_t)malloc(sizeof(node_t));
    newnode->back = NULL;
    newnode->front = NULL;
    
    if(nodeptr == NULL) newnode->data = n;
    else{
        for(int i=0; nodeptr->back!=NULL ; i++) nodeptr = nodeptr->back;
        newnode->front = nodeptr;
        newnode->data = n;
        nodeptr->back = newnode;
    }
    return newnode;
}

nodep_t removeFront(nodep_t nodeptr, int none1, int none2){
    if(nodeptr == NULL) printf("Double link list is empty\n");
    else{
        for(int i=0; nodeptr->front!=NULL ; i++) nodeptr = nodeptr->front;
        nodep_t backnode = nodeptr->back;
        backnode->front = NULL;
        free(nodeptr);
        return backnode;
    }
    return NULL;
}

nodep_t removeBack(nodep_t nodeptr, int none1, int none2){
    if(nodeptr == NULL) printf("Double link list is empty\n");
    else{
        for(int i=0; nodeptr->back!=NULL ; i++) nodeptr = nodeptr->back;
        nodep_t frontnode = nodeptr->front;
        frontnode->back = NULL;
        free(nodeptr);
        return frontnode;
    }
    return NULL;
}

nodep_t empty(nodep_t nodeptr, int none1, int none2){
    if(nodeptr==NULL) printf("Double link list is empty\n"); 
    else{    
        for(int i=0; nodeptr->back!=NULL ; i++) nodeptr = nodeptr->back;
        for(int i=0; nodeptr->front!=NULL ; i++){
            nodep_t staynode = nodeptr;
            nodeptr = nodeptr->front;
            free(staynode);
        }
        free(nodeptr);
    }
    return NULL;
}

nodep_t insert(nodep_t nodeptr, int index, int n){
    for(int i=0; nodeptr->front!=NULL; i++) nodeptr = nodeptr->front;
    int i=0;
    for(i; i<index && nodeptr->back!=NULL; i++) nodeptr = nodeptr->back;
    
    if(i!=index) printf("Invalid command\n");
    else{
        nodep_t newnode = (nodep_t)malloc(sizeof(node_t));
        nodep_t frontnode = nodeptr->front;
        
        newnode->data = n;
        newnode->front = frontnode;
        newnode->back = nodeptr;
        
        if(frontnode!=NULL) frontnode->back = newnode;
        nodeptr->front = newnode;
    }
    return nodeptr;
}

nodep_t removeit(nodep_t nodeptr, int index, int none){
    for(int i=0; nodeptr->front!=NULL; i++) nodeptr = nodeptr->front;
    int i=0;
    for(i; i<index-1 && nodeptr->back!=NULL; i++) nodeptr = nodeptr->back;
    
    if(i!=index-1) printf("Invalid command\n");
    else{
        nodep_t backnode = nodeptr->back;
        nodep_t frontnode = nodeptr->front;

        if(frontnode != NULL) frontnode->back = backnode;
        if(backnode != NULL) backnode->front = frontnode;
        free(nodeptr);

        if(backnode == NULL && frontnode == NULL) return NULL;
        if(backnode == NULL) return frontnode;
        else return backnode;
    }
    return nodeptr;
}

nodep_t print(nodep_t nodeptr, int none1, int none2){
    if(nodeptr == NULL) printf("Double link list is empty\n");
    else{
        for(int i=0; nodeptr->front!=NULL; i++) nodeptr = nodeptr->front;
        for(int i=0; nodeptr->back!=NULL ; i++){
            printf("%d\n", nodeptr->data);
            nodeptr = nodeptr->back;
        }
        printf("%d\n", nodeptr->data);
    }
    return nodeptr;
}


int main(){
    //initial
    char NameofMethod[NumofMethods][12] = {"addFront", "addBack", "removeFront", "removeBack", "empty", "insert", "remove", "print"};
    nodep_t (*Method[NumofMethods])(nodep_t, int, int) = {addFront, addBack, removeFront, removeBack, empty, insert, removeit ,print};

    int NumofInstruction, Index1, Index2;
    scanf("%d", &NumofInstruction);
    nodep_t node = (nodep_t)malloc(sizeof(node_t)*0);
    node = NULL;

    for(int i=0; i<NumofInstruction; i++){
        Index1 = 0;
        Index2 = 0;
        char regI[12];
        scanf(" %s", regI);

        for(int j=0; j< NumofMethods; j++){
            if(strcmp(regI, NameofMethod[j])==0){
                if(j==0 || j==1 || j==5 || j==6) scanf("%d", &Index1);
                if(j==5) scanf("%d", &Index2);

                node = Method[j](node, Index1, Index2);
                break;
            }
        }
    }

    return 0;
}