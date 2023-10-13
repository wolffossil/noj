#include <stdio.h>

int HarshadNumber(int n){
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
    if(tmp==0) return 0;
    
}


int main(){
    int num;
    scanf("%d", &num);
    while(1){
        int tmp=HarshadNumber(num);
        if(tmp=0)
    }
}