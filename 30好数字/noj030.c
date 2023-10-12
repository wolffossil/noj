#include <stdio.h>
#include <math.h>
int main(){
    long long n;
    scanf("%lld",&n);
    long long sum=1;
    long long mod=pow(10,9);
    mod+=7;
    //printf("%lld",mod);
    for(long long i=0;i<n;i++){
        if(i%2==0)
            sum=(sum*5)%mod;
        else
            sum=(sum*4)%mod;
    }

    printf("%lld\n",sum);
    


}