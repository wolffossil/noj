#include <stdio.h>

int a[10]={6,2,5,5,4,5,6,3,7,6};

int convert(int x){
    int res=0;
    if(x==0) return a[x];
    while(x){
        res+=a[x%10];
        x=x/10;
    }
    return res;
}

int calculate(int n){
    n=n-4;
    int sum=0;
    for(int i=0; i<=2000;i++)
        for(int j=0;j<=2000;j++){
            int m=i+j;
 
            if(convert(i)+convert(j)+convert(m)==n) {
                //printf("%d+%d=%d\n",i,j,m);
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