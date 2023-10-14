#include <stdio.h>


void binaryRepresentation(int n) {
    if (n == 0) {
        return;
    } else if (n == 1) {
        printf("2(0)");
    } else if (n == 2) {
        printf("2");
    } else {
        int power = 0;
        int temp = 1;
        while (temp * 2 <= n) {
            temp *= 2;
            power++;
        }
        
        if (temp == n) {
            printf("2(");
            binaryRepresentation(power);
            printf(")");
        } else {
            if(power == 1) {
                printf("2+");
            }
            else{
                printf("2(");
                binaryRepresentation(power);
                printf(")+");
            }
                binaryRepresentation(n - temp);

        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    binaryRepresentation(n);
    printf("\n");

    return 0;
}
