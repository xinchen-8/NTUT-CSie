#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NumofString 110

typedef struct{
    char words[10][11];
}Set;

void split(char *inputString, Set *stringSet){
    int rindex = 0;
    for(int i=0,cindex=0;i<NumofString;i++){
        if(inputString[i]==' '||inputString[i]=='\0'){
            stringSet->words[rindex][cindex] = '\0';
            rindex++;
            cindex = 0;
            if(inputString[i]=='\0') break;
        }
        else stringSet->words[rindex][cindex++] = inputString[i];
    }
    for(int i=rindex;i<10;i++) strcpy(stringSet->words[i]," ");
}
int compare(Set *stringSet, int index, int cindex){
    int buttn = 1;

    for(int i=0;i<10&&strcmp(stringSet[0].words[i]," ")!=0;i++){
        int cimlemwntary_buttn = 0;
        for(int j=0;j<10;j++){
            if(strcmp(stringSet[index].words[j],stringSet[0].words[i])==0||strcmp(stringSet[cindex].words[j],stringSet[0].words[i])==0){
                cimlemwntary_buttn = 1;
                break;
            }
        }
        buttn &= cimlemwntary_buttn;
    }
    int unrecover_buttn = 1;
    for(int i=0;i<10&&strcmp(stringSet[index].words[i]," ")!=0;i++){
        for(int j=0;j<10&&strcmp(stringSet[cindex].words[j]," ")!=0;j++){
            if(strcmp(stringSet[index].words[i],stringSet[cindex].words[j])==0){
                unrecover_buttn = 0;
            }
        }
    }
    return buttn & unrecover_buttn;
}

int main(){
    char mainString[NumofString], regString[NumofString];
    int num;

    scanf("%[^\n]s", mainString);
    scanf("%d", &num);

    Set *stringSet = (Set*)malloc(sizeof(Set)*(num+1));

    split(mainString, stringSet);
    for(int i=1;i<=num;i++){
        scanf(" %[^\n]s", regString);
        split(regString, stringSet+i);
    }
    //compare
    int counter = 0;
    for(int i=1;i<=num;i++){
        for(int j=i+1;j<=num;j++) counter += compare(stringSet, i, j);
    }

    printf("%d", counter);

    free(stringSet);
    return 0;
}