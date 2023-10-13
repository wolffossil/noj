#include <stdio.h>


long long solve(long long n){
    long long result =0;
    for(int i=1; i<n; i++){
        if(i%3==0||i%5==0){
            result+=i;
        }
    }
    return result;
}


long long sum_of_multiples(long long n) {
    n--;  
    long long sum3 = (n / 3) * (3 + (n / 3) * 3) / 2;
    long long sum5 = (n / 5) * (5 + (n / 5) * 5) / 2;
    long long sum15 = (n / 15) * (15 + (n / 15) * 15) / 2;
    return sum3 + sum5 - sum15;
}


int main(){
    long long  T,n;
    scanf("%lld",&T);
    int arr[100000];

    for(long long i=0;i<T;i++){
        scanf("%lld",&n);
        //printf("%lld\n",solve(n));
        //printf("%lld\n",sum_of_multiples(n));
        arr[i]=sum_of_multiples(n);
    }
    for(long long i=0;i<T;i++){

        printf("%lld\n",arr[i]);
    }
}