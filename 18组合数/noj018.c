#include <stdio.h>

int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++) 
            for(int k=0;k<=9;k++)
               for(int x=0;x<=9;x++){
                   if(i+j+k+x==n){
                        sum++;
                   }
            }
    printf("%d",sum);
}