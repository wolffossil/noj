#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++){
            int k=n-i-j;
            if(i*i+j*j==k*k){
                printf("%d\n",i*j*k);
            }
    }
            
}