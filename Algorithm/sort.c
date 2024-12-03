#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define data_size 100000

void insertion_sort(long *data){
    
    for(long i=1; i<data_size; i++){
        long temp = data[i];

        long j=i-1;
        while(temp<data[j] && j>=0){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;
    }
}

long test_algorithm(long *data, void (*algorithm)(long*)){
    long* data_copy = (long*) malloc(data_size*sizeof(long));
    memcpy(data_copy, data, data_size * sizeof(long));

    struct timeval start,end;
    gettimeofday(&start, NULL);
    algorithm(data_copy);
    gettimeofday(&end, NULL);
    
    free(data_copy);
    return end.tv_usec-start.tv_usec;
}

int main(){
    //random
    long data[data_size];
    srand((unsigned) time(NULL));
    for(long i=0; i<data_size; i++) data[i] = rand()%data_size+1;
    printf("The time of algorithm is %lu us\n", test_algorithm(data, insertion_sort));
    // printf("Result:");
    // for(int i=0; i<data_size; i++){
    //     if(i%100==0) printf("\n");
    //     printf("%d ",data[i]);
    // }
    // printf("\n");

    return 0;
}