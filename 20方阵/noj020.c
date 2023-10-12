#include <stdio.h>

int main(){
    long long n,k,j;
    scanf("%lld",&n);
    if(n==0){
        printf("0\n");
    }
    else{
    for(long long i=0;i<n;i++){
        for(k=i;k>0;k--){
            printf("%lld ",k);
        }

        for(j=0;j<n-i-1;j++){
            printf("%lld ",j);
        }
        printf("%lld\n",j);

    }
    }
    return 0;
    
}
