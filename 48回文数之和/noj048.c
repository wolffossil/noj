#include <stdio.h>


int is_palindrome(int num){
    int source=num;
    int result=0;
    while(num>0){
        result=result*10+num%10;
        num=num/10;
    }
    if(source==result) return 1;
    return 0;
}

int convert(int num,int k){
    int result=0;
    int base=1;
    while(num>0){
        result=result+(num%k)*base;
        num=num/k;
        base*=10;
    }
    return result;
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int sum=0;
    for(int i=1;i<n;i++){
        if(is_palindrome(i)&&is_palindrome(convert(i,k)))
            sum+=i; 
    }
    printf("%d\n",sum);


    return 0;
}
