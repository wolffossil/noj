#include <stdio.h>

int HarshadNumber(int n){
    if(n==1){
        return 0;
    }
    int t=n,s=0;
    while(t){
        s=s+t%10;
        t=t/10;
    }
    if(s && n%s==0) return n/s;

    return 0;
}

int judge(int n){
    int tmp=HarshadNumber(n);
    //printf("%d",tmp);
    if(tmp==0) return 0;
    else return 1+judge(tmp);
    
}


int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n", judge(num));
}