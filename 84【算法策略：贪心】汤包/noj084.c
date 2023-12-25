#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
    int t;
    int d;
    int etime;
    int index;
};

int main(){
    int n;
    scanf("%d",&n);
    struct customer a[n];
    for(int i=0; i<n; i++){
        a[i].index=i+1;
        scanf("%d %d",&a[i].t,&a[i].d);
        a[i].etime=a[i].t+a[i].d;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if((a[j].etime>a[j+1].etime)||((a[j].etime==a[j+1].etime)&&a[j].index>a[j+1].index)){
                int tmp=a[j].etime;
                a[j].etime=a[j+1].etime;
                a[j+1].etime=tmp;
                tmp=a[j].index;
                a[j].index=a[j+1].index;
                a[j+1].index=tmp;
            }

        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i].index);
    }

}

/*
3
3 3
1 3
2 3
*/