#include <stdio.h>
#include <math.h>

int judge(int num){

    for(int i=2;i<sqrt(num);i++){
        if(num%i==0){
            return 1;
        }
    }
    return 0;
}


int main(){
    
    long long  k;
    scanf("%lld",&k);
    long long  sum=1;
    long long n=2;
    if(judge(k)==0&&k>20)
    {
        printf("%lld\n",k);
    }
    else{
        while(1){
            sum=sum*n;
            //printf("%lld\n",sum);
            if(sum%k==0){
                printf("%lld\n",n);
                break;
            }
            n++;
        }
    }
    return 0;

}
