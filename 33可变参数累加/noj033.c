#include <stdio.h>
#include <stdarg.h>

int sum(int a,...){
    va_list args;
    va_start(args, a);

    int result = 0;
    result+=a;
    int next;
    while(next=va_arg(args, int)){
        result+=next;

    }
    return result;

}

int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d", &a   , &b , &c , &d , &e , &f);

    int result=sum(a,b,0)-sum(c,d,e,f,0);
    printf("%d\n", result);

}