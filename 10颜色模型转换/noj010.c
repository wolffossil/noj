#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double H,S,V,MIN,MAX;
    double R,G,B;
    scanf("%lf %lf %lf", &R, &G, &B);
    R=R*100.000000;G=G*100.000000;B=B*100.000000;
    V=fmax(R,G);
    V=fmax(V,B);
    MAX=V;
    V=MAX/255.0000000;
    MIN=fmin(R,G);
    MIN=fmin(MIN,B);
    if(V==0){
        S=0;
    }
    else{
        S=100.00000000*(MAX-MIN)/MAX;
    }



    if(MAX==R){
        H=0+60.0000000*((G-B)/(MAX-MIN));
    }
    else if(MAX==G){
        H=120.000000+60.0000000*((B-R)/(MAX-MIN));
    }
    else if(MAX==B){
        H=240.0000000+60.000000*((R-G)/(MAX-MIN));
    }
    
    if(H<0){
        H=H+360.000000;
    }

 
     printf("%.4lf,%.4lf%%,%.4lf%%\n", round(H * 10000.0) / 10000.0, round(S * 10000.0) / 10000.0, round(V * 10000.0) / 10000.0);
}