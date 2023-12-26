#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    double result;
    scanf("%d",&n);
    FILE *file = fopen("rr.dat","w");

    for(int i=1;i<=n;i++){
        result=sqrt(i);
        fprintf(file, "%.6f\n", result);
    }
    fclose(file);
    file = fopen("rr.dat", "r");

    while (fscanf(file, "%lf", &result) == 1) {
        printf("%.6f ", result);
    }
    fclose(file);
}


