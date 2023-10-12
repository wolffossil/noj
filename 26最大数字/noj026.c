#include <stdio.h>


int judge(int num){
    int t1=9;
    while(num>0){
        int t2=num%10;
        num/=10;
        if(t1<t2){
            return 0;
        }
        t1=t2;
    }
    return 1;

}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        if(judge(i)){
            printf("%d\n",i);
            break;
        }
    }


}