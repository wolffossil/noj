#include <stdio.h>
#include <math.h>
#define MAX 101

int m,n,d;
int min_steps=-1;
int used[MAX][MAX]={0};

void dfs(int x,int y,int steps){
    
    //若找到符合条件，则进行比较，找最小操作数
    if(x==d||y==d){
        if(steps <min_steps||min_steps==-1)
            min_steps=steps;  

        return;
    }
    //避免无限深搜，用数组标记搜索过的样例
    if(used[x][y]==1){
        return;
    }

    used[x][y]=1;

    //倒空一个杯子
    dfs(0,y,steps+1);
    dfs(x,0,steps+1);

    //装满一个杯子
    dfs(m,y,steps+1);
    dfs(x,n,steps+1);

    //把水从x倒入y里
    int sum=x+y;
    int x_next,y_next;
    if(sum>n){
        x_next=sum-n;
        y_next=n;
    }
    else{
        x_next=0;
        y_next=sum;
    }
    dfs(x_next,y_next,steps+1);

    //把水从y倒入x里
    if(sum>m){
        x_next=m;
        y_next=sum-m;
    }
    else{
        x_next=sum;
        y_next=0;
    }
    dfs(x_next,y_next,steps+1);

    used[x][y]=0;

}

int main(){

    scanf("%d %d %d",&m,&n,&d);
    dfs(0,0,0);
    printf("%d\n",min_steps);


}