#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define inputNum 1050
#define wordNum 21

typedef struct{
    int times:6;
    char word[wordNum];
}Word;

int wordcmp(const void *a, const void *b){
    Word *obj1 = (Word *)a;
    Word *obj2 = (Word *)b;
    if(obj1->times > obj2->times) return -1; 
    else if(obj1->times < obj2->times) return 1;
    else return strcmp(obj1->word,obj2->word);
}

void split(char **wordlist, char *inputString){
    int index = 0;
    for(index; index<inputNum&&inputString[index]!=' '&&inputString[index]!='\0'; index++) (*wordlist)[index] = inputString[index];
    (*wordlist)[index] = '\0';
    if(inputString[index]!='\0') split(wordlist+1, inputString+index+1);
}

int main(){
    //input
    char inputString[inputNum];
    char P[wordNum], Q[wordNum];

    scanf("%[^\n]", &inputString);
    scanf(" %s", &P);
    scanf(" %s", &Q);

    //split for a wordlist
    int numofwords = 1;
    for(int i=0;i<=inputNum&&inputString[i]!='\0';i++) if(inputString[i]==' ') numofwords++;
    
    char **wordlist = (char **)malloc(sizeof(char *)*numofwords);
    for(int i=0;i<numofwords;i++) wordlist[i] = (char *)malloc(sizeof(char)*wordNum);

    split(wordlist, inputString);
    //for(int i=0;i<numofwords;i++) printf("%s\n",*(wordlist+i));// test

    for(int mode=1;mode<4;mode++){
        for(int i=0;i<numofwords;i++){
            if(strcmp(wordlist[i],P)==0){
                switch(mode){
                    case 1:
                        printf("%s ",Q); break;
                    case 2:
                        printf("%s %s ",Q , P); break;
                    case 3:
                        printf(""); break;
                }
            }
            else printf("%s ", wordlist[i]);
        }
        printf("\n");
    }
    //for(int i=0;i<numofwords;i++) printf("%s\n",wordlist[i]);


    //initial object
    Word wordobjs[numofwords];
    for(int i=0;i<numofwords;i++){
        int btn = 0;
        strcpy(wordobjs[i].word, wordlist[i]);
        wordobjs[i].times = 1;

        for(int j=i-1;j>=0;j--){
            if(strcmp(wordobjs[j].word, wordlist[i])==0){
                btn=1;
                wordobjs[j].times++;
            }
        }
        if(btn){
            strcpy(wordobjs[i].word," ");
            wordobjs[i].times = 0;
        }
    }
    //for(int i=0;i<numofwords;i++) printf("%d:%s\n",wordobjs[i].times,wordobjs[i].word);

    qsort(wordobjs, numofwords, sizeof(Word), wordcmp);
    for(int i=0;i<numofwords;i++) if(wordobjs[i].times!=0) printf("%s %d\n", wordobjs[i].word, wordobjs[i].times);

    //free all
    for(int i=0;i<numofwords;i++) free(wordlist[i]);
    free(wordlist);
    return 0;
}