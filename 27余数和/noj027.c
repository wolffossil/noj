#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=k%i;
    }
    printf("%d\n",sum);

}