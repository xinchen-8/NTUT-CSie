#include <stdio.h>

struct course{
        int name;
        int num;
        char time[3][3];
};

int main(){

    struct course myc[3];

    for(int index=0;index<3;index++){
        scanf("%d",&myc[index].name);
        scanf("%d",&myc[index].num);
        for(int i=0;i<myc[index].num;i++) scanf("%s",&myc[index].time[i]);
    }

    int button = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<myc[i].num;j++){
            //myc[i].time[j]
            for(int k=i+1;k<3;k++){
                for(int l=0;l<myc[k].num;l++){

                    //printf("%d %d,%s:%d,%s\n",myc[i].time[j]==myc[k].time[l],myc[i].name,myc[i].time[j],myc[k].name,myc[k].time[l]);


                    if(myc[i].time[j][0]==myc[k].time[l][0]&&myc[i].time[j][1]==myc[k].time[l][1]&&(i!=k || j!=l)){
                        printf("%d,%d,%s\n",myc[i].name,myc[k].name,myc[k].time[l]);
                        button = 0;
                    }
                }   
            }
        }
    }

    if(button)printf("correct");

    return 0;
}