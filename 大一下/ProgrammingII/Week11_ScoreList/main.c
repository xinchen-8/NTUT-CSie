#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum scoreType_s{ G, GPA, S }scoreType_t; // 評分類別
typedef enum G_s{ Aplus=95, A=87, Aduce=82, Bplus=78, B=75, Bduce=70, Cplus=68, C=65, Cduce=60, F=50, X=0 }G_t; // 等第評分
typedef enum GPA_s{ b4dot3=95, b4dot0=87, b3dot7=82, b3dot3=78, b3dot0=75, b2dot7=70, b2dot3=68, b2dot0=65, b1dot7=60, b1=50, b0=0 }GPA_t; // GPA評分
typedef enum S_s{ b90to100=95, b85to89=87, b80to84=82, b77to79=78, b73to76=75, b70to72=70, b67to69=68, b63to66=65, b60to62=60, b1to59=50, b0to0=0 }S_t; // 百分制區間評分
typedef union student_s{
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
}student_t; // 學生分數類型

typedef struct {
    int ID;
    float avescore;
}Student;

int studentcmp(const void *a, const void *b){
    Student *p1 = (Student *)a;
    Student *p2 = (Student *)b;
    return p1->avescore-p2->avescore;
}

int main(){

    int NumofCourses;
    scanf("%d", &NumofCourses);

    char **method = (char **)malloc(sizeof(char *)*NumofCourses);
    for(int i=0;i<NumofCourses;i++){
        method[i] = (char *)malloc(sizeof(char)*4);
        scanf(" %s", method[i]);
    }
    int NumofStudents;
    scanf("%d", &NumofStudents);

    Student *students = (Student *)malloc(sizeof(Student)*NumofStudents);
    student_t **studentData = (student_t **)malloc(sizeof(student_t*)*NumofStudents);
    
    for(int i=0;i<NumofStudents;i++){
        studentData[i] = (student_t *)malloc(sizeof(student_t)*NumofCourses);
        
        scanf("%d", &(students+i)->ID);
        for(int j=0;j<NumofCourses;j++){
            char regstr[7]="";
            scanf("%s", regstr);

            if(strcmp(method[j], "G")==0){
                if(strcmp(regstr, "A+")==0) studentData[i][j].G = Aplus;
                else if(strcmp(regstr, "A")==0) studentData[i][j].G = A;
                else if(strcmp(regstr, "A-")==0) studentData[i][j].G = Aduce;
                else if(strcmp(regstr, "B+")==0) studentData[i][j].G = Bplus;
                else if(strcmp(regstr, "B")==0) studentData[i][j].G = B;
                else if(strcmp(regstr, "B-")==0) studentData[i][j].G = Bduce;
                else if(strcmp(regstr, "C+")==0) studentData[i][j].G = Cplus;
                else if(strcmp(regstr, "C")==0) studentData[i][j].G = C;
                else if(strcmp(regstr, "C-")==0) studentData[i][j].G = Cduce;
                else if(strcmp(regstr, "F")==0) studentData[i][j].G = F;
                else if(strcmp(regstr, "X")==0) studentData[i][j].G = X;
            }
            else if(strcmp(method[j], "GPA")==0){
                if(strcmp(regstr, "4.3")==0) studentData[i][j].S = b4dot3;
                else if(strcmp(regstr, "4.0")==0) studentData[i][j].S = b4dot0;
                else if(strcmp(regstr, "3.7")==0) studentData[i][j].S = b3dot7;
                else if(strcmp(regstr, "3.3")==0) studentData[i][j].S = b3dot3;
                else if(strcmp(regstr, "3.0")==0) studentData[i][j].S = b3dot0;
                else if(strcmp(regstr, "2.7")==0) studentData[i][j].S = b2dot7;
                else if(strcmp(regstr, "2.3")==0) studentData[i][j].S = b2dot3;
                else if(strcmp(regstr, "2.0")==0) studentData[i][j].S = b2dot0;
                else if(strcmp(regstr, "1.7")==0) studentData[i][j].S = b1dot7;
                else if(strcmp(regstr, "1")==0) studentData[i][j].S = b1;
                else if(strcmp(regstr, "0")==0) studentData[i][j].S = b0;
            }
            else if(strcmp(method[j], "S")==0){
                if(strcmp(regstr, "90-100")==0) studentData[i][j].GPA = b90to100;
                else if(strcmp(regstr, "85-89")==0) studentData[i][j].GPA = b85to89;
                else if(strcmp(regstr, "80-84")==0) studentData[i][j].GPA = b80to84;
                else if(strcmp(regstr, "77-79")==0) studentData[i][j].GPA = b77to79;
                else if(strcmp(regstr, "73-76")==0) studentData[i][j].GPA = b73to76;
                else if(strcmp(regstr, "70-72")==0) studentData[i][j].GPA = b70to72;
                else if(strcmp(regstr, "67-69")==0) studentData[i][j].GPA = b67to69;
                else if(strcmp(regstr, "63-66")==0) studentData[i][j].GPA = b63to66;
                else if(strcmp(regstr, "60-62")==0) studentData[i][j].GPA = b60to62;
                else if(strcmp(regstr, "1-59")==0) studentData[i][j].GPA = b1to59;
                else if(strcmp(regstr, "0")==0) studentData[i][j].GPA = b0to0;
            }
            //printf("%d\n", studentData[i][j].score);
        }
    }

    for(int i=0;i<NumofStudents;i++){
        int Sum = 0;
        for(int j=0;j<NumofCourses;j++) Sum += studentData[i][j].score;
        students[i].avescore = Sum*1.0/NumofCourses;

    }

    qsort(students,NumofStudents,sizeof(Student),studentcmp);
    for(int i=0;i<NumofStudents;i++) printf("%d %.f\n",students[i].ID,floor(students[i].avescore));

    for(int i=0;i<NumofStudents;i++) free(studentData[i]);
    free(studentData);
    free(students);
    for(int i=0;i<NumofCourses;i++) free(method[i]);
    free(method);
    return 0;
}