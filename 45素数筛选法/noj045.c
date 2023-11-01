#include <stdio.h>
#define N 10000000
int vis[N+1]={0};
int pr[N+1];//存质数
int cnt=0;

void Euler_sieve(int n)
{
    int i,j;
    for(i=2;i<=n;i++){
        if(vis[i]==0){
            pr[cnt++]=i;
        }
        for(j=0;j<cnt;j++){
            if(i*pr[j]>n)//超出范围停止
                    break;
            vis[i*pr[j]]=1;
            if(i%pr[j]==0)//找到最小质因子后停止搜索
                    break;
        }
    }
}
    

int main(){
    int n;
    scanf("%d",&n);
    Euler_sieve(n);
    printf("%d\n",cnt);
    /*for(int i=0;i<cnt;i++){
        printf("%d\n",pr[i]);
    }*/
    return 0;
}