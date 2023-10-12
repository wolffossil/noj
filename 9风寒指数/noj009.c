#include <stdio.h>
#include <math.h>

int main(){
    double v,t;
    scanf("%lf %lf",&v,&t);
    double result=13.12+0.6215*t-11.37*pow(v,0.16)+0.3965*t*pow(v,0.16);
    printf("%.0lf",result);
}