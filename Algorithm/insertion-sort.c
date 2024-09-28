#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define data_size 10000

int insertion_sort(int *data){
    
    for(int i=1; i<data_size; i++){
        int temp = data[i];

        int j=i-1;
        while(temp<data[j] && j>=0){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;
    }
}


int main(){
    //random
    int data[data_size];
    srand((unsigned) time(NULL));
    for(int i=0; i<data_size; i++) data[i] = rand()%(data_size*10)+1;

    struct timeval start,end;
    gettimeofday(&start, NULL);
    insertion_sort(data);
    gettimeofday(&end, NULL);

    printf("The time of algorithm is %d us\n", end.tv_usec-start.tv_usec);// 57 ms
    // printf("Result:");
    // for(int i=0; i<data_size; i++){
    //     if(i%100==0) printf("\n");
    //     printf("%d ",data[i]);
    // }
    // printf("\n");

    return 0;
}