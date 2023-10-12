#include <stdio.h>

int count(int n){
    if(n==0){
        return 1;
    }

    int lens=0;
    while(n>0){
        n=n/10;
        lens++;
    }
    return lens;

}

int main(){
    int a,b;
    int result;
    scanf("%d %d",&a,&b);
    result = a*b;
    int len=count(result);
    len++;
    int a_len=count(a);
    int b_len=count(b);
    for(int i=0;i<len-a_len;i++){
        printf(" ");
    }
    printf("%d\n",a);
    printf("x");
    for(int i=0;i<len-b_len-1;i++){
        printf(" ");
    }
    printf("%d\n",b);
    for(int i=0;i<len;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<b_len;i++){
        int tmp=b%10;
        b=b/10;
        tmp=a*tmp;
        int t_len=count(tmp);
        if(i==b_len-1){
            printf("+");
            t_len+=1;
        }
        for(int j=0;j<len-i-t_len;j++){
            printf(" ");
        }
        printf("%d",tmp);
        for(int k=0;k<i;k++){
            printf(" ");
        }
        printf("\n");
    }
    for(int i=0;i<len;i++){
        printf("-");
    }
    printf("\n");
    printf(" %d",result);

}