#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int solve(int N,int M,int *bad){
    int dp[N+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<M;i++){
        dp[bad[i]]=-1;
    }
    dp[0]=1;
    if(dp[1]!=-1)dp[1]=1;
    else dp[1]=0;
    for(int i=2;i<=N;i++){
        if(dp[i]==-1){
            dp[i]=0;
        }
        else{
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }

    }
    return dp[N];

}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    int *bad=(int *)malloc(M*sizeof(int));
    for(int i=0;i<M;i++){
        scanf("%d",&bad[i]);
    }
    printf("%d\n",solve(N,M,bad));
}