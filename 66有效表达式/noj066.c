#include <stdio.h>

int n;
int sum=0;
int flag1=0,flag2=0;
void solve(int x){
    if(x==2*n){
        sum++;
        return ;
    }
    else{
        if(flag1+1<=n) 
        {   flag1++;
            solve(x+1);
            flag1--;
        }
        if(flag1-flag2>0&&flag2+1<=n) 
        {
            flag2++;
            solve(x+1);
            flag2--;
        }
    }


}

int main(){
    scanf("%d",&n);
    flag1=1;
    solve(1);
    printf("%d\n",sum);

}