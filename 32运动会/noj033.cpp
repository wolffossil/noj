#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> used(40000,vector<int>(40000,0));


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

/*
0 1 1 1 1 0
0 1 0 1 0 1
0 1 1 0 1 1
0 1 0 1 0 1
1 1 1 1 1 1
2 1 0 0 0 0*/