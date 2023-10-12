#include <stdio.h>

int main(){
    long long m,n,t,num;
    int zero=0;
    num=0;
    scanf("%lld %lld",&m,&n);
    t=m;
    while(t>0){
        t=t/10;
        num++;
    }
    if(num==n||num>n){
        printf("%lld\n",m);
    }
    else{
        num=n-num;
        while(num--){
            printf("%d",zero);
        }
        printf("%lld\n",m);
    }

}

