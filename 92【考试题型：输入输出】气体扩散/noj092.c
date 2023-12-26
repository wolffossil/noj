#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    double result=sqrt(b/a);
    printf("%.4lf\n",result);
}

/*
349.03 352.04
*/