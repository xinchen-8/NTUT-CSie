#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inputNumofString 51

int letter(char letter){
    if(letter>='a'&&letter<='z') return -1;
    else if(letter>='A'&&letter<='Z') return 1;
}

int compute(char *eachstringList, int k){
    
    int linkcounter = 0, comparenumber, changeindex;
    int recordlinkcounter = 0;
    for(int i=0;i<inputNumofString&&eachstringList[i]!='\0';i++){
        comparenumber = letter(eachstringList[i]);
        changeindex = i+k;

        for(int index=i;index<inputNumofString&&eachstringList[index]!='\0';index++){
            //printf("%d %d: %d\n",i,index,linkcounter);
            if(index==changeindex){
                changeindex+=k;
                comparenumber*=-1;
            }
            if(letter(eachstringList[index])==comparenumber) linkcounter++;
            else break;
        }
        recordlinkcounter = (recordlinkcounter>linkcounter)?recordlinkcounter:linkcounter;
        linkcounter = 0;
    }

    if(recordlinkcounter<2*k) return 0;
    else return recordlinkcounter-(recordlinkcounter%k);
}

int main(){

    int num;
    scanf("%d", &num);

    int *intList = (int *)malloc(sizeof(int)*num);
    char ** stringList = (char **)malloc(sizeof(char *)*num);
    for(int i=0;i<num;i++){
        stringList[i] = (char *)malloc(sizeof(char)*inputNumofString);
        scanf(" %s %d", stringList[i], intList+i);
    }

    for(int i=0;i<num;i++) printf("%d\n", compute(stringList[i], intList[i]));

    free(intList);
    for(int i=0;i<num;i++) free(stringList[i]);
    free(stringList);

    return 0;
}