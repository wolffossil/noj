#include <stdio.h>

int lsKeith(int N) {
    int len = 0;
    int originalN = N;
    int sequence[100]; 
    int a[100];
    int sum=0;
    while(N>0){
        sequence[len++] = N%10;
        N=N/10;
        
    }
    int index=0;
    for(int i=len-1; i>=0; i--){
        a[index++]=sequence[i];
        sum+=sequence[i];
    }
    int start=0;
    while(1){
       a[index++]=sum;
       sum=sum+sum-a[start++];
       if(sum==originalN){
            return 1;
       }
       if(sum>originalN){
            return 0;
       }
   
    }
 

    return 0; 
}

int main() {
    int N;
    scanf("%d", &N);

    if (lsKeith(N) == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
