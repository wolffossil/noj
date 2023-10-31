#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    int m,N;
    double a,b;
    scanf("%d %lf %lf %d",&m,&a,&b,&N);
    srand(RAND_MAX);
    double sum=0;
    double result;
    if(m==1){
        for(int i=0;i<N;i++){
            double randomValue=a + ((double)rand() / RAND_MAX) * (b - a);
            double x1=pow(randomValue,4);
            double x2=exp(-randomValue);
            sum+=x1*x2;
        }
        result=(b-a)*sum/N;
    }
    else if(m==2){
        for(int i=0;i<N;i++){
            double randomValue=a + ((double)rand() / RAND_MAX) * (b - a);
            sum+=pow(randomValue,2)+1;
        }
        result=(b-a)*sum/N;
    }
    else if(m==3){
        for(int i=0;i<N;i++){
            double randomValue=a + ((double)rand() / RAND_MAX) * (b - a);
            sum+=cos(randomValue);
        }
        result=(b-a)*sum/N;
    }
    else if(m==4){
         for(int i=0;i<N;i++){
            double randomValue=a + ((double)rand() / RAND_MAX) * (b - a);
            sum+=pow(randomValue,0.5)*(randomValue-2);
        }
        result=(b-a)*sum/N;

    }
    else if(m==5){
         for(int i=0;i<N;i++){
            double randomValue=a + ((double)rand() / RAND_MAX) * (b - a);
            sum+=2*sin(randomValue)-5*cos(randomValue);
        }
        result=(b-a)*sum/N;
    }

    printf("%.6lf\n", result);


}

