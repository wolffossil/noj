#include <stdio.h>
#include <math.h>

int a[300][300];
int mark[300][300]={0};
int counts=0;

int is_notused(int x1,int y1,int x2,int y2){

    int flag=0;
    for(int i=x1;i<=x2;i++){
        if(mark[i][y1]==0||mark[i][y2]==0){
            flag=1;
        }
        mark[i][y1]=1;
        mark[i][y2]=1;
    }
    for(int j=y1;j<=y2;j++){
        if(mark[x1][j]==0||mark[x2][j]==0){
            flag=1;
        }
        mark[x1][j]=1;
        mark[x2][j]=1;
    }

    /*for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++){
             if(i==x1||i==x2||j==y1||j==y2){
                if(mark[i][j]==0){
                    flag=1;
                }
                mark[i][j]=1;
             }
        }*/

    if(flag)
        return 1;
    else 
        return 0;
}

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

int sums(int x1,int y1,int x2,int y2){
    

    
    if( x2-x1==1&&y2-y1==1){
        if(a[x1][y1]==1&&a[x1][y2]==1&&a[x2][y1]==1&&a[x2][y2]==1&&is_notused(x1,y1,x2,y2)){
            //printf("x1:%d y1:%d x2:%d y2:%d counts:%d\n",x1,y1,x2,y2,counts);
            counts++;
            return 1;

        }
        else{
            return 0;
        }
    }
    if (x2==x1 || y2==y1) {
        return 0;  // 子矩阵太小，不可能是完美矩阵
    }
    
    if(is_perfect(x1,y1,x2,y2)&&is_notused(x1,y1,x2,y2)){
        //printf("x1:%d y1:%d x2:%d y2:%d counts:%d\n",x1,y1,x2,y2,counts);
        counts++;
    }
    sums(x1+1,y1,x2,y2);
    sums(x1,y1+1,x2,y2);
    sums(x1,y1,x2-1,y2);
    sums(x1,y1,x2,y2-1);
    return 1;

}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    sums(0,0,n-1,m-1);
    printf("%d\n",counts);

    return 0;

}

