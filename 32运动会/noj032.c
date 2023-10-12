#include <stdio.h>
int used[40000][40000];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            used[i][j] = 1;
    int nums=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(used[i][j]){
                nums++;
                int x=i+i;
                int y=j+j;
                while(x<n&&y<n){
                    used[x][y] = 0;
                    x+=i;
                    y+=j;
                }
            }
        }
    }
    printf("%d\n",2*nums+1);

}