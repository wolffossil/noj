#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





int main(){
    int n;
    scanf("%d",&n);
    long long a[1001];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    int sum=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]==a[j]) {
                sum++;
                break;
            }
        }
    }
    printf("%d\n",sum);
}

/*
10
1 10 20 1 25 1 10 30 25 1
*/