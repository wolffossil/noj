#include <stdio.h>

//最小二乘法
struct point{
    int x;
    int y;
};

int main(){
    int n;
    scanf("%d",&n);
    struct point arr[n];
    double sum_x=0,sum_y=0;
    for(int i=0; i<n; i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
        sum_x+=arr[i].x;
        sum_y+=arr[i].y;
    }
    double x_m=sum_x/n;
    double y_m=sum_y/n;
    double a=0,b=0;
    double tmp1,tmp2;
    for(int i=0; i<n; i++){
        tmp1+=(arr[i].x-x_m)*(arr[i].y-y_m);
        tmp2+=(arr[i].x-x_m)*(arr[i].x-x_m);

    }
    b=tmp1/tmp2;
    a=y_m-b*x_m;
    printf("Y=%.4lf+%.4lf*X",a,b);


}

/*
7
150 6450
200 7450
250 8445
300 9450
350 11450
400 15450
600 18450
*/