#include <stdio.h>


int judge(int x,int y){
    if(x==1){
        return 1;
    }
    if(y%x==0){
        return 0;
    }
    else{
        return judge(y%x,x);
    }
    return 0;

}

int main(){
    int n;
    scanf("%d",&n);
    int count = 0;
    for(int i=1;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            if(judge(i,j)){
                count++;
                printf("(%d,%d)\n",i,j);
            }
    }
    int sum=3+2*count;
    printf("%d\n",sum);
}