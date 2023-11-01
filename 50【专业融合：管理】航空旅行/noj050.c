#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int a[3];
    int d,e;
    for(int i=0;i<n;i++){
        int flag=0;
        scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&d,&e);
        for(int j=0;j<2;j++)
            for(int k=0;k<2-j;k++){
                if(a[k]>a[k+1])
                {
                    int tmp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=tmp;
                }
        }
        if(a[2]+a[1]<=d&&a[0]<=e){
                flag=1;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");

    }

}

/*
3
1 1 1 15 5
8 7 6 15 5
8 5 7 15 6
*/