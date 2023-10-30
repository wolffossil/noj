#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i=1;
    while(1){
        if(n-i>0){
            n=n-i;
            i++;
        }
        else{
            break;
        }
    }
    printf("%d\n",n);


}