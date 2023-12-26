#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    double V,T;
    scanf("%lf %lf",&V,&T);
    double c=331.3*sqrt(1.0+T/273.15);
    double M=(V*1000.0)/3600.0/c;
    printf("%.3lf ",M);
    if(M<=0.8){
        printf("subsonic");
    }
    else if(M>0.8&&M<=1.2){
        printf("transonic");
    }
    else if(M>1.2&&M<=5.0){
        printf("supersonic");
    }
    else if(M>5.0&&M<=10.0){
        printf("hypersonic");
    }

}

/*
920 -49.90
*/