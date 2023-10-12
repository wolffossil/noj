#include <stdio.h>


int judge(int x,int y){
    if(x==1){
        return 1;
    }

    if(y%x){
        return 1;
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
                //printf("(%d,%d)\n",i,j);
                count++;
            }
    }
    int sum=3+2*count;
    printf("%d\n",sum);
}