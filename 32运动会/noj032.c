#include <stdio.h>
#include <math.h>


int euler(int n){
    int result=n;

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            result=result/i*(i-1);
            while(n%i==0){
                n=n/i;
            }
        }
        
    }

    if(n>1){
        result = result/n*(n-1);
    }
    return result;
}

// 计算欧拉函数
int eulerTotient(int n) {
    int result=n; // 初始化结果为 n

    // 遍历从 2 到 sqrt(n) 的所有质数
    for (int i=2; i<=sqrt(n);i++) {
        // 如果 i 是 n 的因子
        if (n%i == 0) {
            // 不断除以 i，直到它不再是 n 的因子
            while (n%i == 0) {
                n/=i;
            }
            // 更新结果
            result-=result/i;
        }
    }
    // 如果 n 是一个大于 1 的质数
    if (n>1) {
        result-=result/n;
    }

    return result;
}

int main(){

    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        sum+=eulerTotient(i);
    }
    sum=sum*2+1;
    printf("%d\n",sum);

}