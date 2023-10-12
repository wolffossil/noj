#include <stdio.h>
#include <math.h>


int is_prime(int n){
    if(n==2||n==3||n==5){
        return 1;
    }

    if(n%2==0||n%3==0||n%5==0||n==1){
        return 0;
    }
    
    //枚举素因子，能被整除说明不是素数。
    for(int i=5;i<=sqrt(n);i+=6){
        if(n%i==0||n%(i+2)==0){
            return 0;
        }

    }
    return 1;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int num=0;
    for(int i=a;i<=b;i++){
        if(is_prime(i)){
            num++;
        }

    }
    printf("%d\n",num);

}