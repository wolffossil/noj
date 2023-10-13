#include <stdio.h>
#include <stdarg.h>

double avg(int n, ...) {
    va_list args;
    va_start(args, n);

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += va_arg(args, double);
    }

    va_end(args);

    return sum / n;
}

int main() {
    double a, b, c, d, e;
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    double result = avg(2, a, b) - avg(3, c, d, e);
    
    printf("%.4lf\n", result);

    return 0;
}
