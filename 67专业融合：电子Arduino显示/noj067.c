#include <stdio.h>

int a[10]={6,2,5,5,4,5,6,3,7,6};

int calculate(int n){
    n=n-4;
    int sum=0;
    for(int i=0; i<=9;i++)
        for(int j=0;j<=9;j++){
            int m=i+j,s=0;
            if(m>=10){
                s=s+a[m/10]+a[m%10];
            }
            else{
                s=s+a[m];
            }
            if(a[i]+a[j]+s==n) {
                printf("%d+%d=%d\n",i,j,m);
                sum++;
            }
        }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", calculate(n));
}