#include <stdio.h>

//求最大公约数
long long  gcd(long long  x,long long  y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);

}


int main(){
    
    double n;
    scanf("%lf",&n);
    n=n*100000000000;
    long long x=(long long )n;
    long long  common_divisor=gcd(100000000000,x);
    long long  a=x/common_divisor;
    long long  b=100000000000/common_divisor;
    printf("%lld/%lld",a,b);
    return 0;

}