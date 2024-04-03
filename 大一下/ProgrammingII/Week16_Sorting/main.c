#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void smp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void select_sort(int *list, int num, int *count){
    int point = 0;
    for(int i=0;i<num;i++){
        point = i;
        for(int j=i+1;j<num;j++){
            count[0]++;
            if(list[point]>list[j]) point=j;
        }
        if(i!=point){
            smp(&list[point], &list[i]);
            count[1]+=3;
        }
    }
}

void insert_sort(int *list, int num, int *count){
    int temp = 0,j;
    for(int i=1;i<num;i++){
        j=i;
        temp = list[i];
        count[1]++;

        for(;j>0&&list[j-1]>temp;j--){
            count[0]++;
            list[j] = list[j-1];
            count[1]++;
        }
        if(j!=i){
            list[j] = temp;
            count[1]++;
        }
    }
}

int main(){
    int num;
    scanf("%d", &num);
    int *list1 = malloc(num*sizeof(int));
    int *list2 = malloc(num*sizeof(int));
    int *count = calloc(0,4*sizeof(int));

    for(int i=0;i<num;i++){
        scanf("%d", &list1[i]);
        list2[i] = list1[i];
    }
    select_sort(list1, num, count);
    insert_sort(list2, num, count+2);

    printf("%d %d\n", count[0], count[1]);
    printf("%d %d\n", count[2], count[3]);

    free(count);
    free(list1);
    free(list2);
    return 0;
}