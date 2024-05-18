#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct Node{
    int index;
    int days;
    int NumofNext;
    int maxDay;
    struct Node **next;
}Node;

int MaxDayinNode(Node *node){
    if (node->maxDay != -1) return node->maxDay; 
    if (node->NumofNext == 0) return node->maxDay = node->days;
    
    int maxDay = 0;
    for (int i = 0; i < node->NumofNext; i++) {
        maxDay = MAX(maxDay, MaxDayinNode(node->next[i]));
    }
    return node->maxDay = maxDay + node->days;
}

int main(){
    int NumofProjects;
    scanf("%d", &NumofProjects);

    for(int i=0;i<NumofProjects;i++){// i: index of Projects
        
        //initial(build link list)
        int NumofNode;
        scanf("%d", &NumofNode);
        Node *nodes = (Node *)malloc(sizeof(Node)*NumofNode);

        for(int j=0; j<NumofNode; j++){// notice: different from input(j=index-1)           
            int NumofNext;
            scanf(" %d %d", &nodes[j].days, &NumofNext);
            nodes[j].next = (Node **)malloc(sizeof(Node*)*NumofNext);
            nodes[j].NumofNext = NumofNext;
            nodes[j].maxDay = -1;
            nodes[j].index = j+1;

            for(int k=0; k<NumofNext; k++){
                int index;
                scanf(" %d", &index);
                nodes[j].next[k] = &nodes[index-1];
            }
        }
        //

        //compute
        int maxDays = 0;
        for(int j=0; j<NumofNode; j++){
            maxDays = MAX(maxDays, MaxDayinNode(&nodes[j]));
        }
        //
        printf("%d\n", maxDays);

        //free
        for(int j=0; j<NumofNode; j++) free(nodes[j].next);
        free(nodes);
    }

  return 0;
}