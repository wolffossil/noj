#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    int used[1001];
    memset(used,-1,sizeof(used));
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        used[a[i]]++;
    }
    int sum=0;
    for(int i=0;i<=1000;i++){
        if(used[i]!=-1){
            sum+=used[i];
        }
    }
    printf("%d\n",sum);

}

/*
10
1 10 20 1 25 1 10 30 25 1
*/