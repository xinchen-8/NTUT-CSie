#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define InputSize 100
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct node{
    int coeff;
    struct node *next;
}node;

int *inputPoly(int *NumofPoly){

    char regInput[InputSize];
    char regTokens[InputSize/2][10];
    scanf(" %[^\n]s", regInput);

    //split()
    char *token = strtok(regInput, " ");
    while(token!=NULL){
        strcpy(regTokens[(*NumofPoly)++], token);
        token = strtok(NULL, " ");
    }

    int *poly = (int*)malloc(*NumofPoly*sizeof(int));
    for(int i=0; i<*NumofPoly; i++) poly[i] = atoi(regTokens[i]);
    return poly;
}

node *buildLinkList(int *poly, int NumofPoly){
    node *Node = (node*)malloc(sizeof(node));
    Node->coeff = poly[0];
    Node->next = NULL;

    for(int i=1; i<NumofPoly; i++){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->coeff = poly[i];
        newNode->next = Node;
        Node = newNode;
    }
    return Node;
}

void breakLinkList(node *Node){
    node *temp = Node;
    while(temp!=NULL){
        Node = Node->next;
        free(temp);
        temp = Node;
    }
}

void output(int *AnsList, int NumofPoly){
    int ZeroButtn = 1;
    for(int i=NumofPoly-1; i>=0; i--){
        if(AnsList[i]==0) continue;
        if(i!=NumofPoly-1 && AnsList[i]>0) printf("+");
        
        if(AnsList[i]==-1&&i!=0) printf("-");
        else if(AnsList[i]!=1&&AnsList[i]!=0) printf("%d", AnsList[i]);

        if(AnsList[i]!=0&&i!=0&&i!=1) printf("x^%d", i);
        else if(i==1) printf("x");
        else if(i==0&&AnsList[i]==1) printf("%d", AnsList[i]);

        ZeroButtn &= (AnsList[i]==0);
    }
    if(ZeroButtn) printf("0");
    printf("\n");
}

void SumofPolys(node *Node1, node *Node2, int NumofMPoly){
    int *SumList = (int *)calloc(NumofMPoly, sizeof(int));
    
    int countPower = 0;
    while((Node1!=NULL || Node2!=NULL)){
        int num1 = (Node1!=NULL)? Node1->coeff : 0;
        int num2 = (Node2!=NULL)? Node2->coeff : 0;
        SumList[countPower++] = num1 + num2;
        if (Node1 != NULL) Node1 = Node1->next;
        if (Node2 != NULL) Node2 = Node2->next;
    }

    output(SumList, NumofMPoly);
    free(SumList);
}

void SubofPolys(node *Node1, node *Node2, int NumofMPoly){
    int *SubList = (int *)calloc(NumofMPoly, sizeof(int));
    
    int countPower = 0;
    while((Node1!=NULL || Node2!=NULL)){
        int num1 = (Node1!=NULL)? Node1->coeff : 0;
        int num2 = (Node2!=NULL)? Node2->coeff : 0;
        SubList[countPower++] = num1 - num2;
        if (Node1 != NULL) Node1 = Node1->next;
        if (Node2 != NULL) Node2 = Node2->next;
    }

    output(SubList, NumofMPoly);
    free(SubList);
}

void MultiPoly(node *Node1, node *Node2, int NumofSPoly){
    int *MultiList = (int *)calloc(NumofSPoly, sizeof(int));
    int basePower = 0;
    while(Node1!=NULL){
        node *regNode = Node2;
        int countPower = 0;
        while(regNode!=NULL){
            int num1 = (Node1!=NULL)? Node1->coeff : 0;
            int num2 = (regNode!=NULL)? regNode->coeff : 0;
            MultiList[basePower+countPower++] += num1*num2;
            regNode = regNode->next;
        }
        Node1 = Node1->next;
        basePower++;
    }
    output(MultiList, NumofSPoly);
    free(MultiList);
}

int main(){
    //initial & input
    int NumofPoly1 = 0;
    int *poly1 = inputPoly(&NumofPoly1);
    int NumofPoly2 = 0;
    int *poly2 = inputPoly(&NumofPoly2);

    node* Node1 = buildLinkList(poly1, NumofPoly1);
    node* Node2 = buildLinkList(poly2, NumofPoly2);

    SumofPolys(Node1, Node2, MAX(NumofPoly1,NumofPoly2));
    SubofPolys(Node1, Node2, MAX(NumofPoly1, NumofPoly2));
    MultiPoly(Node1, Node2, NumofPoly1+NumofPoly2-1);

    breakLinkList(Node1);
    breakLinkList(Node2);
    free(poly1);
    free(poly2);
    return 0;
}