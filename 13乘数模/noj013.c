#include <stdio.h>

int main(){
    long long a,b,m;
    scanf("%lld %lld %lld", &a, &b, &m);
    long long result;
    result = (a%m)*(b%m)%m;
    printf("%lld\n", result);


}