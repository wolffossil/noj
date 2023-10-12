#include <stdio.h>

int main(){
    long long  x,y;
    scanf("%lld %lld",&x,&y);
    long long  sum=0;

    while(x>0){
        
        printf("%lld %lld\n",x,y);
        if(x%2){
            sum+=y;
        }
        x=x/2;
        y=y*2;
    }
    printf("%lld",sum);


}