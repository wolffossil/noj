#include <stdio.h>

int a[10]={6,2,5,5,4,5,6,3,7,6};

int calculate(int n){
    n=n-4;
    int sum=0;
    for(int i=0; i<=9;i++)
        for(int j=0;j<=9;j++){
            if(i+j>=10) break;
            if(a[i]+a[j]+a[i+j]==n) sum++;
        }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", calculate(n));
}