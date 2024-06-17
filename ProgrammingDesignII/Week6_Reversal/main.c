#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d", &num);

    int *list = malloc(num*sizeof(int));
    for(int i=0;i<num;i++) scanf(" %d", &list[i]);

    int count = 0;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(list[j]<list[i]) count++;
        }
    }

    printf("%d",count);
    free(list);
    return 0;
}