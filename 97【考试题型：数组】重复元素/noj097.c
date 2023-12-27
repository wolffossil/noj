#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct number{
    long long data;
    int sign;
};


int main(){
    struct number used[1001];
    for(int i=0;i<1001;i++){
        used[i].sign=0;
    }
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    int k=0;

    used[k++].data=a[0];
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<k;j++){
            if(used[j].data==a[i]){
                used[j].sign++;
                flag=1;
                break;
            }
        }
        printf("\n");
        if(!flag){
            used[k++].data=a[i];
        }
    }
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=used[i].sign;
    }
    printf("%d\n",sum);

}

/*
10
1 10 20 1 25 1 10 30 25 1
*/