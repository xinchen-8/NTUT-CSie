#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    int NumOfNext;
    int *next;
}Node;

int CheckNodeIndex(Node *NodeArray, int NumOfArray, int data){
    for(int i=0; i<NumOfArray; i++){
        if(NodeArray[i].data == data) return i;
    }
    return -1;
}

Node *AddNewNode(Node *NodeArray, int *NumOfArray, int data){
    if(CheckNodeIndex(NodeArray, *NumOfArray, data)==-1){
        Node *NewArrey = (Node *)malloc(++(*NumOfArray) * sizeof(Node));
        
        for(int i=0; i<(*NumOfArray)-1; i++) NewArrey[i] = NodeArray[i];
        NewArrey[*NumOfArray-1].data = data;
        NewArrey[*NumOfArray-1].NumOfNext = 0;
        NewArrey[*NumOfArray-1].next = NULL;

        free(NodeArray);
        return NewArrey;
    }
    return NodeArray;
}

Node *AddWayNode(Node *Node, int addIndex){
    int *newNext = (int *)malloc(++(Node->NumOfNext) * sizeof(int));
    if(Node->next!=NULL){
        for(int i=0; i<Node->NumOfNext-1; i++) newNext[i] = Node->next[i];
    }
    newNext[Node->NumOfNext-1] = addIndex;
    free(Node->next);
    Node->next = newNext;

    // printf("the nexts of node %d (%d):", Node->data, Node->NumOfNext);
    // for(int i=0; i<Node->NumOfNext; i++) printf(" %d", Node->next[i]);
    // printf("\n");

    return Node;
}

int *Qpop(int *queue, int *buttom){
    for(int i=0; i<*buttom; i++) queue[i] = queue[i+1];
    (*buttom)--;
    return queue;
}

int *Qpush(int *queue, int *buttom, int index){
    queue[(*buttom)++] = index;
    return queue;
}

int *BreadthFirstSearch(Node *NodeArray, int NumOfArray, int StartIndex){
    int *path = calloc(NumOfArray, sizeof(int));
    for(int i=0; i<NumOfArray; i++) path[i] = -1;

    int *queue = calloc(NumOfArray, sizeof(int));
    for(int i=0; i<NumOfArray; i++) queue[i] = -1;
    int buttom = 0, *buttomPtr = &buttom;

    path[StartIndex] = -2;
    Qpush(queue, buttomPtr, StartIndex);
    

    while(buttom!=0){
        // printf("queue: ");
        // for(int i=0; i<NumOfArray; i++) printf("%d ", queue[i]);
        // printf("\n");

        for(int i=0; i<NodeArray[queue[0]].NumOfNext; i++){
            int currentIndex = NodeArray[queue[0]].next[i];
            //printf("%d %d: num is %d and next is %d\n",i,  queue[0], NodeArray[queue[0]].NumOfNext, currentIndex);

            if(path[currentIndex]==-1){
                path[currentIndex] = queue[0];
                queue = Qpush(queue, buttomPtr, currentIndex);
            }
        }
        queue = Qpop(queue, buttomPtr);
    }

    free(queue);
    return path;//free outside
}

int main(){
    char RegString[10], *token;
    scanf("%[^\n]s", RegString);

    int *InputNum = calloc(4, sizeof(int));// NumOfWays, StartNode, EndNode, PassNode
    token = strtok(RegString, " ");
    for(int i=0; i<4; i++){
        InputNum[i] = (token!=NULL)? atoi(token): -1;
        token = strtok(NULL, " ");
    }//printf("input num: %d %d %d %d\n", InputNum[0], InputNum[1], InputNum[2], InputNum[3]);

    Node *NodeArray = NULL;
    int NumofArray = 0;
    int *NumofArrayPtr = &NumofArray;

    for(int i=0; i<InputNum[0]; i++){
        int RegInt[2];
        scanf("%d %d", RegInt, RegInt+1);

        for(int j=0; j<2; j++){
            NodeArray = AddNewNode(NodeArray, NumofArrayPtr, RegInt[j]);
            RegInt[j] = CheckNodeIndex(NodeArray, NumofArray, RegInt[j]);
        }
        AddWayNode(NodeArray+RegInt[0], RegInt[1]);
        AddWayNode(NodeArray+RegInt[1], RegInt[0]);
    }
    
    //BFS
    if(InputNum[3]==-1){
        int *stack = calloc(NumofArray, sizeof(int));
        int buttom = 0;
        int *path = BreadthFirstSearch(NodeArray, NumofArray, CheckNodeIndex(NodeArray, NumofArray, InputNum[1]));
        //printf("first index is %d\n", CheckNodeIndex(NodeArray, NumofArray, InputNum[1]));
        
        // printf("Path: ");
        // for(int i=0; i<NumofArray; i++) printf("%d ", path[i]);
        // printf("\n");

        if(path[CheckNodeIndex(NodeArray, NumofArray, InputNum[2])]==-1) printf("NO\n");
        else{
            int currentIndex = CheckNodeIndex(NodeArray, NumofArray, InputNum[2]);
            while(currentIndex != CheckNodeIndex(NodeArray, NumofArray, InputNum[1])){
                stack[buttom++] = currentIndex;
                currentIndex = path[currentIndex];
            }
            stack[buttom++] = CheckNodeIndex(NodeArray, NumofArray, InputNum[1]);

            printf("%d\n", buttom-1);
            for(--buttom; buttom>=0; buttom--) printf("%d ", NodeArray[stack[buttom]].data);
        }
        free(path);
        free(stack);
    }
    else{
        int *stack = calloc(NumofArray*2, sizeof(int));
        int buttom = 0;
        
        int *path1 = BreadthFirstSearch(NodeArray, NumofArray, CheckNodeIndex(NodeArray, NumofArray, InputNum[1]));
        //printf("path2\n");
        int *path2 = BreadthFirstSearch(NodeArray, NumofArray, CheckNodeIndex(NodeArray, NumofArray, InputNum[3]));

        if(path1[CheckNodeIndex(NodeArray, NumofArray, InputNum[3])]==-1 || path2[CheckNodeIndex(NodeArray, NumofArray, InputNum[2])]==-1) printf("NO\n");
        else{
            int currentIndex = CheckNodeIndex(NodeArray, NumofArray, InputNum[2]);
            while(currentIndex != CheckNodeIndex(NodeArray, NumofArray, InputNum[3])){
                stack[buttom++] = currentIndex;
                currentIndex = path2[currentIndex];
            }

            currentIndex = CheckNodeIndex(NodeArray, NumofArray, InputNum[3]);
            while(currentIndex != CheckNodeIndex(NodeArray, NumofArray, InputNum[1])){
                stack[buttom++] = currentIndex;
                currentIndex = path1[currentIndex];
            }
            stack[buttom++] = CheckNodeIndex(NodeArray, NumofArray, InputNum[1]);

            printf("%d\n", buttom-1);
            for(--buttom; buttom>=0; buttom--) printf("%d ", NodeArray[stack[buttom]].data);
        }
        free(path1);
        free(path2);
        free(stack);
    }

    //need to check free again
    free(InputNum);
    return 0;
}