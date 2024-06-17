#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct student_s{
char name[50];
int score;
}student_t;

void input(student_t s[], int n){
    for(int i=0;i<n;i++){
        scanf(" %s",(s+i)->name);
        scanf("%d",&((s+i)->score));
    }
}

void getHigh(student_t s[], int n){
    int hightindex = 0;
    for(int i=0;i<n;i++) if(s[i].score>s[hightindex].score) hightindex = i;
    printf("%s\n", s[hightindex].name);
}

int getAverage(student_t s[], int n){
    int Sum = 0;
    for(int i=0;i<n;i++) Sum += s[i].score;
    return floor(Sum/n);
}

int main(){
    int NumofStudents;
    scanf("%d", &NumofStudents);

    student_t *studentList = (student_t *)malloc(sizeof(student_t)*NumofStudents);
    input(studentList, NumofStudents);
    getHigh(studentList, NumofStudents);
    printf("%d\n", getAverage(studentList, NumofStudents));

    free(studentList);
    return 0;
}