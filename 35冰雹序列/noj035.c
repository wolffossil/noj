#include <stdio.h>

void collatz(int n){
    if(n==1){
        printf("%d",n);
        return;
    }  
    if(n%2==1){
        printf("%d ",n);
        collatz(3*n+1);
    } 
    else{
        printf("%d ",n);
        collatz(n/2);
    }
}




int main(){
    int n;
    scanf("%d",&n);
    collatz(n);

}