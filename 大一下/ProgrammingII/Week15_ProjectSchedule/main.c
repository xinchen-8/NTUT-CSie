#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
int time;
int waiteNodeNum;
int waiteNode[100];
struct node_s* next;
}node_t;
typedef node_t* nodep;

nodep findNode(nodep headNode, int index_node){
    nodep currentNode = headNode;
    for(int i = 0; i < index_node; i++){
        currentNode = currentNode->next;
    }
    return currentNode;
}

void findMaxWay(int *dist, nodep headnode, int index){
    for(int i = 0; i < findNode(headnode, index)->waiteNodeNum; i++){
        int waitNode = findNode(headnode, index)->waiteNode[i];
        if(dist[waitNode] < dist[index] + findNode(headnode, waitNode)->time){
            dist[waitNode] = dist[index] + findNode(headnode, waitNode)->time;
            findMaxWay(dist, headnode, waitNode);
        }
    }
}

int main(){
    int num_projects;
    scanf("%d", &num_projects);

    for(int project = 0; project < num_projects; project++){
        int num_projects_nodes;
        scanf("%d", &num_projects_nodes);

        nodep headNode = NULL, prevNode = NULL;
        for(int index_node = 0; index_node < num_projects_nodes; index_node++){
            int time_node, num_waitNodes;
            scanf("%d %d", &time_node, &num_waitNodes);

            //create node
            nodep newNode = (nodep)malloc(sizeof(node_t));
            newNode->time = time_node;
            newNode->waiteNodeNum = num_waitNodes;
            for(int index_waitNode = 0; index_waitNode < num_waitNodes; index_waitNode++){
                scanf("%d", &newNode->waiteNode[index_waitNode]);
                newNode->waiteNode[index_waitNode] -= 1;
            }
            newNode->next = NULL;
            
            //link node like array (OnO)
            if(index_node == 0) headNode = prevNode = newNode;
            else{
                prevNode->next = newNode;
                prevNode = newNode;
            }
        }

        int *dist = calloc(num_projects_nodes, sizeof(int));
        for(int i=0; i<num_projects_nodes; i++) dist[i] = findNode(headNode, i)->time;
        findMaxWay(dist, headNode, 0);

        int max=0;
        for(int i=0; i<num_projects_nodes; i++){
            if(dist[i] > max) max = dist[i];
        }
        printf("%d\n",max);

        //kill project
        free(dist);

        while(headNode != NULL){
            nodep tempNode = headNode;
            headNode = headNode->next;
            free(tempNode);
        }
    }

    return 0;
}