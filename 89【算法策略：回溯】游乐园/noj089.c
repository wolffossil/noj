#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
int map[100][100]={0};
int used[100]={0};
int MAX=0;;

int max(int x, int y){
    if(x>y) return x;
    return y;
}

void dfs(int s,int sum){
    //printf("sum:%d\n",sum);
    MAX=max(MAX,sum);
    for(int i=0;i<n;i++){
        if(map[s][i]&&!used[i]){
            used[i]=1;
            dfs(i,sum+map[s][i]);
            used[i]=0;
        }
    }
}


int main(){
    scanf("%d %d",&n,&m);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
    }
    for(int i=1;i<=n;i++){
        dfs(i,0);
    }
    printf("%d\n",MAX);

}

/*
4 4
1 2 1
2 3 10
1 3 100
1 4 1000
*/