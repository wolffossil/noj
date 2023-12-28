#include <stdio.h>

int main() {
    double Ti, Tf;
    scanf("%lf %lf", &Ti, &Tf);


    double m_liquid, c_liquid;
    scanf("%lf %lf", &m_liquid, &c_liquid);


    double m_container, c_container;
    scanf("%lf %lf", &m_container, &c_container);


    double delta_T = Tf - Ti;
    double Q = (m_liquid * c_liquid + m_container * c_container) * delta_T;


    double percentage_container = (m_container * c_container * delta_T / Q) ;
    double percentage_liquid = (m_liquid * c_liquid * delta_T / Q) ;

    printf("%.2lfkJ,%.2lf%%,%.2lf%%\n", Q / 1000, percentage_container, percentage_liquid);

    return 0;
}


/*
20 80
0.250 4186
0.500 900
*/