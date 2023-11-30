#include <stdio.h>

int main(){
   int a[7];
   int a_3[4]={0,5,3,1};
   while(1){
        scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
        if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0){
            break;
        }
        int sum=0;
        sum+=a[6];
        sum+=a[5];
        sum+=a[4];
        int sub=a[2]-a[4]*5;
  
        sum+=a[3]/4;
        if(a[3]%4){
            sum++;
        }
        int x=a_3[a[3]%4];
        if(sub>=0){
            if(a[2]-sub>x){
                sum+=(a[2]-sub-x)/9;
                if((a[2]-sub-x)%9){
                    sum++;
                }
            }
        }
        x=36*sum-(a[3]*9+a[2]*4+a[4]*16+a[5]*25+a[6]*36);
        if(a[1]>x){
            sum+=(a[1]-x)/36;
            if((a[1]-x)%36){
                sum++;
            }
        } 
        printf("%d\n",sum);
   }
   return 0;


}



/*
1 1 1 1 1 1
2 2 2 2 2 2
1 2 3 4 5 6
0 0 0 0 0 0 
*/