#include <stdio.h>

int main(){
    long long a,b,m;
    scanf("%lld %lld %lld", &a, &b, &m);
    long long result=1;
    while(b!=0){
        if(b%2){
            result=(result*a)%m;
        }
        a=(a*a)%m;
        b=b/2;
    }
    printf("%lld\n", result);

}