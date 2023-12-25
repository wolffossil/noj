#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int dp[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        dp[i]=a[i];
    }
    for(int i=1;i<n;i++){
        if(dp[i]+dp[i-1]>dp[i]){
            dp[i]=dp[i]+dp[i-1];
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(dp[i]>max) max=dp[i];
    }
    printf("%d\n",max);
    
    
    
}

/*
7
2 -4 1 9 -6 7 -3
*/