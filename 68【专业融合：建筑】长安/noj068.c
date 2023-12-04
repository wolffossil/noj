#include <stdio.h>
int bx,by,px,py;
int sum=0;
int next[2][2]={{0,1},{1,0}};
void calculate(int x,int y){
    //printf("x: %d y: %d\n",x,y);
    if(x==bx&&y==by){
        sum++;
        return ;
    }
    else{
        for(int i=0;i<2;i++){
            int x1=x+next[i][0];
            int y1=y+next[i][1];
            if((x1==px&&y1==py)||x1>bx||y1>by){
                continue;
            }
            calculate(x1,y1);
        }
    }
    
    
}

int main(){
    while(scanf("%d %d %d %d",&bx,&by,&px,&py)){
        if(bx==0&&by==0&&px==0&&py==0){
            break;
        }
        sum=0;
        calculate(0,0);
        printf("%d\n",sum);
    }

}

/*
8 6 5 3
8 6 8 6
8 6 9 6
0 0 0 0

3 3 0 3
0 0 0 0
*/