#include <stdio.h>

int n;

int judge(int start){
    int sum=0;
    for(int i=start;i<n;i++){
        sum+=i;
        if(sum==n){
            return 1;
        }
        else if(sum>n){
            return 0;
        }
    }
    return 0;
}

int main(){

   int nums = 1;
   scanf("%d",&n);
   for(int i=1;i<=n/2;i++){
     nums+=judge(i);
   }
   printf("%d\n",nums);


}