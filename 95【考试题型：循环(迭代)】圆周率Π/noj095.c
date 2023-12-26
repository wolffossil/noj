#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    double result=3.0;
    double flag=1.0;
    for(int i=2;i<=(n-1)*2;i+=2){
        result+=4.0/(double)(i*(i+1)*(i+2))*flag;
        flag=-flag;
    }
    printf("%.7lf", result);
}
