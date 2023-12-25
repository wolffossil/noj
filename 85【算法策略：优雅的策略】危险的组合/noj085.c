#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int num;
int a[30];


void dfs(int i,int flag){

    if(i==n) {
        if(flag>=1) num++;
        return;
    }
    for(int j=0;j<2;j++){
        a[i]=j;
        if(i>=2&&a[i-1]==a[i]&&a[i-1]==a[i-2]&&a[i]==1){
            dfs(i+1,flag+1);
        }
        else{
            dfs(i+1,flag);
        }

    }


}


int main(){
    
    while(1){
        scanf("%d",&n);
        num=0;
        if(n<=0) break;
        dfs(0,0);
        printf("%d\n",num);
    }
}