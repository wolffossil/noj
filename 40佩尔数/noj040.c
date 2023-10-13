#include <stdio.h>

int PB(int n){
    int p0=0,p1=1,pn,i;
    for(i=0;i<=n;i++)
        if(i==0) pn=p0;
        else if(i==1) pn=p1;
        else{
            pn=2*p1+p0;
            p0=p1;
            p1=pn;
        }
    return pn;
}

int PA(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    if(n%2){
        return  2*PB(n-1)+PA(n-2);
    }
    else{
        return 2*PA(n-1)+PB(n-2);
    }
}



int  pell(int n){
    if(n%2)
        return PA(n);
    else
        return PB(n);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",pell(n));
}