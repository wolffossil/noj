#include <stdio.h>

long long calculateTotalLength(long long  N, long long  X) {
    long long totalLength = N;
    long long N_X=N-X;
    while(N_X>0){

        if(N_X%X==0){
            long long n=N_X/X;
            totalLength+=(2*n-1)*X;
            break;
        }
        else if(N_X/X>=1){
            
            long long n=N_X/X;
            totalLength+=2*n*X;
            int tmp=N_X-X*n;
            N_X=X;
            X=tmp;
            
        }

    }
    return totalLength;
    

    
}

int main() {
    long long  N, X;
    scanf("%lld %lld", &N, &X);  
    long long totalLength;
    if(N-X>=X)
        totalLength=calculateTotalLength(N, X);
    else
        totalLength=calculateTotalLength(N, N-X);
    printf("%lld\n", totalLength);  

    return 0;
}
