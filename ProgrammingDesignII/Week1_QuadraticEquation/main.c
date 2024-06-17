# include <stdio.h>
# include <math.h>

int main(){
    
    int a,b,c = 0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if (b * b - 4 * a * c < 0){
        printf("%1.1f+%1.1fi\n",( -b ) / ( 2.0 * a ),( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2.0 * a )));
        printf("%1.1f-%1.1fi",( -b ) / ( 2.0 * a ),( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2.0 * a )));
    }
    else{
        printf("%1.1f\n",((-b) + sqrt(b * b - 4 * a * c)) / (2.0 * a));
        printf("%1.1f",((-b) - sqrt(b * b - 4 * a * c)) / (2.0 * a));
    }
    return 0;
}