#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUM 1000000
#define MAX(a, b) (a>b)?a:b

typedef struct node_s{
int machine;
int time;
struct node_s* next;
}node_t;

int main(){
    int num_machines, num_jobs;
    int *num_threads = malloc(sizeof(int)*num_machines);

    //input
    scanf("%d %d", &num_machines, &num_jobs);
    node_t** head = malloc(sizeof(node_t)*num_jobs);

    for(int index_job = 0; index_job<num_jobs; index_job++){
        scanf("%d", &num_threads[index_job]);
        for(int index_thread = 0; index_thread<num_threads[index_job]; index_thread++){
            
            //create node
            node_t* new_node = malloc(sizeof(node_t));
            scanf("%d %d", &new_node->machine, &new_node->time);
            new_node->next = NULL;

            if(index_thread == 0) head[index_job] = new_node;
            else{
                node_t* current = head[index_job];
                while(current->next != NULL) current = current->next;
                current->next = new_node;
            }
        }
    }

    int *time_jobs = calloc(num_jobs, sizeof(int));
    int *time_machines = calloc(num_machines, sizeof(int));

    //compute
    int loop_button = 1;
    while(loop_button){

        int index_min = MAXIMUM, time_min = MAXIMUM, AllNUll_button = 1;
        for(int index_job = 0; index_job<num_jobs; index_job++){
            if(head[index_job]==NULL) continue;

            int current_machine = time_machines[head[index_job]->machine];
            int current_job = time_jobs[index_job];
            int current_time = MAX(current_machine, current_job);
            current_time += head[index_job]->time;

            if(current_time < time_min){
                time_min = current_time;
                index_min = index_job;
            }
            AllNUll_button = 0;
        }
        if(AllNUll_button) break;

        time_machines[head[index_min]->machine] = time_jobs[index_min] = time_min;
        node_t *currentNOde = head[index_min];
        head[index_min] = head[index_min]->next;
        free(currentNOde);
    }
    

    //output
    int total = 0;
    for(int i=0; i<num_machines; i++) total += time_jobs[i];
    printf("%d\n", total);

    //kill nodes
    free(head);
    free(num_threads);
    return 0;
}