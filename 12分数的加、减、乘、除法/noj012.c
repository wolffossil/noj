#include <stdio.h>
#include <string.h>

//求最大公约数
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);

}


int main(){
    
    int a1,a2,b1,b2;
    int result1,result2,common_divisor;
    scanf("%d/%d",&a1,&a2);
    scanf("%d/%d",&b1,&b2);

    //加法
    result1=a1*b2+a2*b1;
    result2=a2*b2;
    common_divisor=gcd(result1,result2);
    result1/=common_divisor;
    result2/=common_divisor;
    //simplify(&result1,&result2);
    printf("(%d/%d)+(%d/%d)=%d/%d\n",a1,a2,b1,b2,result1,result2);

    //减法
    result1=a1*b2-a2*b1;
    result2=a2*b2;
    common_divisor=gcd(result1,result2);
    result1/=common_divisor;
    result2/=common_divisor;
    //simplify(&result1,&result2);
    printf("(%d/%d)-(%d/%d)=%d/%d\n",a1,a2,b1,b2,result1,result2);

    //乘法
    result1=a1*b1;
    result2=a2*b2;
    common_divisor=gcd(result1,result2);
    result1/=common_divisor;
    result2/=common_divisor;
    //simplify(&result1,&result2);
    printf("(%d/%d)*(%d/%d)=%d/%d\n",a1,a2,b1,b2,result1,result2);

    //除法
    result1=a1*b2;
    result2=a2*b1;
    common_divisor=gcd(result1,result2);
    result1/=common_divisor;
    result2/=common_divisor;
    //simplify(&result1,&result2);
    printf("(%d/%d)/(%d/%d)=%d/%d\n",a1,a2,b1,b2,result1,result2);


    return 0;

}