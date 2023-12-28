#include <stdio.h>
#include <math.h>


double solve_area(double AB,double BC,double CD,double DA,double diagonal){
    double s_ABC = (AB + BC + diagonal) / 2;
    double s_ADC = (CD + DA + diagonal) / 2;
    double area_ABC = sqrt(s_ABC * (s_ABC - AB) * (s_ABC - BC) * (s_ABC - diagonal));
    double area_ADC = sqrt(s_ADC * (s_ADC - CD) * (s_ADC - DA) * (s_ADC - diagonal));
    return area_ABC +area_ADC;
}

double solve_angle(double ab,double da,double ac){
    double cos=(ab * ab + da * da - ac * ac) / (2 * ab * da);
    return acos(cos)*180.0/M_PI;
    
}


int main(){
    double ab,bc,cd,da,ac;
    scanf("%lf %lf %lf %lf %lf",&ab,&bc,&cd,&da,&ac);
    double area=solve_area(ab,bc,cd,da,ac);
    double angle=solve_angle(ab,da,ac);
    printf("%.6lf %.1lf",area,angle);
}