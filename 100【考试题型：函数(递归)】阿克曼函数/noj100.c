#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int A(int x,int y){
    if(x==0) return y+1;
    if(y==0) return A(x-1,1);
    return A(x-1,A(x,y-1));
}


int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int result=A(m,n);
    printf("%d\n",result);
}