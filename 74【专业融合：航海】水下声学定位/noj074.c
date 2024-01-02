#include <stdio.h>
#include <math.h>

#define PI 3.1415926

double solve_area(double AB,double BC,double CD,double DA,double diagonal){
    double s_ABC = (AB + BC + diagonal)/2;
    double s_ADC = (CD + DA + diagonal)/2;
    double area_ABC = sqrt(s_ABC * (s_ABC - AB) * (s_ABC - BC) * (s_ABC - diagonal));
    double area_ADC = sqrt(s_ADC * (s_ADC - CD) * (s_ADC - DA) * (s_ADC - diagonal));
    return area_ABC +area_ADC;
}

double solve_angle(double AB,double BC,double CD,double DA,double diagonal,double area){
    double pi = 3.1415926f;
    double angle=(4 *area )/(BC * BC + DA * DA - AB * AB - CD * CD);
    return atan(angle)*180.0/pi;
    
}


int main(){
    double ab,bc,cd,da,ac;
    scanf("%lf %lf %lf %lf %lf",&ab,&bc,&cd,&da,&ac);
    double area=solve_area(ab,bc,cd,da,ac);
    double angle=solve_angle(ab,bc,cd,da,ac,area);
    printf("%.6lf %.1lf",area,angle);
}

/*
7 5 5 7 6
*/