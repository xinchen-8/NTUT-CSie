#include <stdio.h>
#include <math.h>

int findGCD(int a, int b){
    if(a<b) return findGCD(b, a);
    if(b==0) return a;
    else return findGCD(b, a%b);
}

void computing(int a, int b,int *up, int *down, int *neg){// a/b
    *neg = (a<0)^(b<0);//printf("\na:%d b:%d\n", a, b);
    int gcd = (a==0) ? 1:findGCD(abs(a), abs(b));
    *up = abs(a)/gcd;
    *down = abs(b)/gcd;
}

int main(){
    int turn, x1, x2, y1, y2;
    int mu, bu, md, bd, negm, negb;
    
    scanf("%d", &turn);
    for(int i=0; i<turn; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        computing(y1-y2, x1-x2, &mu, &md, &negm);//m
        computing(x2*y1-x1*y2, x2-x1, &bu, &bd, &negb);//b

        //output
        printf("y = ");
        if(mu!=0){
            if(negm==1) printf("-");
            if(md==1){
                if(mu==1) printf("x");
                else printf("%dx", mu);
            }
            else printf("%d/%dx",mu ,md);
        }
        if(bu!=0){
            if(mu==0){
                if(negb==1) printf("-");
                else NULL;
            }
            else{
                if(negb==1) printf(" - ");
                else printf(" + ");
            }
            if(bd==1) printf("%d", bu);
            else printf("%d/%d",bu ,bd);
        }
        printf("\n");
    }
    return 0;
}