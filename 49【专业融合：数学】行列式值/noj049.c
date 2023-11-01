#include <stdio.h>

int laplace(int a[100][100],int r,int c,int n);
int determinant(int a[100][100],int n);




int main(){
    int n;
    int a[100][100];
    int result;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    
    result=determinant(a,n);
    printf("%d\n",result);
    return 0;
    

}

int determinant(int a[100][100],int n){
    int result=0;
    int tmp=1;
    int subset;

    if(n==1){
        result=a[0][0];
    }
    else{
        for(int i=0;i<n;i++){
            subset=laplace(a,i,0,n);
            result+=a[i][0]*tmp*subset;
            tmp*=-1;
        }
    }
    return result;
}
int laplace(int a[100][100],int r,int c,int n){
    int result=0;
    int subset[100][100];
    int s_i,s_j;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            s_i=i;
            s_j=j;
            if(i!=r&&j!=c){
                if(i>r) i--;
                if(j>c) j--;
                subset[i][j] = a[s_i][s_j];
                i=s_i;
                j=s_j;
            }
        }
    
    if(n>=2){
        result=determinant(subset,n-1);
    }
    return result;
}

/*
3
2 6 3
1 0 2
5 8 4
*/