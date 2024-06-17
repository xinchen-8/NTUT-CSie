#include <stdio.h>

int main(){

    float w,h = 0.0;
    scanf("%f",&w);
    scanf("%f",&h);
    printf("%1.1f",(w)/(h*h/10000));

    return 0;
}