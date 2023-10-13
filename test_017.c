#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a,b,i;
    scanf("%d",&n);
    double m[n],s=0;
    for(a=1,b=2;a<=n,i<n;a++,b++,i++)
    {
        if (b<10)
        {
            m[i]=a+b*0.1;
            printf("%.1lf+",m[i]);
        }
        else if (b>10 && b<100 && b%10!=0)
        {
            m[i]=a+b*0.01;
            printf("%.2lf+",m[i]);
        }
        else if (b%10==0)
        {
            m[i]=a+b*0.01;
            printf("%.1lf+",m[i]);
        }
        s=s+m[i];
    }
    printf("\b=%.2lf",s);
    return 0;
}