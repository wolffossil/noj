#include <stdio.h>
#include <math.h>

int a[300][300];
int counts=0;

int is_perfect(int x1, int y1, int x2, int y2){
    int zeros=0,ones=0;
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++){
            if(i==x1||i==x2||j==y1||j==y2){
                if(a[i][j]!=1){
                    return 0;
                }
            }
            else{
                if(a[i][j]==0){
                    zeros++;
                }
                else{
                    ones++;
                }
            }
        }
    
    if(abs(zeros-ones)<=1){
        return 1;
    }
    else{
        return 0;
    }

}

void sums(int n,int m){
    int MIN=fmin(n,m);
    for(int k=MIN;k>1;k--){
        for(int i=0;i<n-k+1;i++)
            for(int j=0;j<m-k+1;j++){
                if(k==2){
                    int x1=i,x2=i+k-1,y1=j,y2=j+k-1;
                    if(a[x1][y1]==1&&a[x1][y2]==1&&a[x2][y1]==1&&a[x2][y2]==1){
                        counts++;
                    }
                }
                else if(is_perfect(i,j,i+k-1,j+k-1)){
                    counts++;
                }
            }

    }


}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    sums(n,m);
    printf("%d\n",counts);

    return 0;

}

/*
4 4
1 1 1 1
1 0 1 1 
1 1 0 1
1 1 1 1

5 5
1 0 1 1 1
1 0 1 0 1
1 1 0 1 1
1 0 0 1 1
1 1 1 1 1

2 2 
1 1 
1 1

*/