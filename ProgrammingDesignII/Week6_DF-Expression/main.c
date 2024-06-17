#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coordinate{
    int x,y;
};

void separation(struct coordinate *reg, struct coordinate *ref, int size, int index){//0leftup 1rightup 2leftdn 3rightdn
    reg->x = ref->x + (index%2)*size;
    reg->y = ref->y + (index/2)*size;
    (reg+1)->x = reg->x +size-1;
    (reg+1)->y = reg->y +size-1;
}

void setregion(int *graph, struct coordinate *position, int public_size, int num){
    for(int i=position[0].y;i<=position[1].y;i++){
        for(int j=position[0].x;j<=position[1].x;j++){
            graph[i*public_size+j] = num;
        }
    }
    //printf("set_region A:(%d, %d)\n",position->x,position->y);
    //printf("set_region B:(%d, %d)\n",(position+1)->x, (position+1)->y);
}

char *DF_expression(char *list, int *graph, struct coordinate *pos, int public_size, int size, int index){//printf("now char:%s\n",list);//printf("now size:%d\n",size);
    struct coordinate position[2];
    separation(position, pos, size, index++);
    if(list[0]=='0') setregion(graph, position, public_size, 0);
    else if(list[0]=='1') setregion(graph, position, public_size, 1);
    else if(list[0]=='2') for(int i=0;i<4;i++) list = DF_expression(++list, graph, position, public_size, size/2, i);
    //for(int i=0;i<public_size;i++){for(int j=0;j<public_size;j++){printf("%d", graph[i*public_size+j]);}printf("\n");}printf("\n");
    return list;
}

int main(){
    char list[100];//input
    int size;
    scanf("%s", list);
    scanf("%d", &size);

    int *graph = malloc(size*size*sizeof(int));//initial
    memset(graph, 0, size*size*sizeof(int));
    struct coordinate position[2];
    position->x=0;
    position->y=0;

    DF_expression(list, graph, position, size, size, 0);//main func

    /*test
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d", graph[i*size+j]);
        }
        printf("\n");
    }*/

    //output
    int button = 1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(graph[i*size+j]){
                printf("%d,%d\n", i, j);
                button = 0;
            }
        }
    }
    if(button) printf("all white");

    free(graph);
    return 0;
}