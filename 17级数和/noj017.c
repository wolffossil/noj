#include <stdio.h>

int main() {
    int n;
    double sum = 1.2;
    scanf("%d", &n);
    printf("1.2");
    for (int i = 2; i <= n; i++) {
        if((i+1)%10==0)
        {
            printf("+%d.%d", i, (i+1)/10);
        }
        else{
            printf("+%d.%d", i, i + 1);
        }
        
        if(i>=9){
            sum+=i+((double)(i+1))/100.0;
        }
        else{
            sum+=i+((double)(i+1))/10.0;
        }
       
    }

    printf("=%.2lf\n", sum);


    return 0;
}
