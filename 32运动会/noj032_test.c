#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countConnectedPoints(int N) {
    int count = 0;
    for (int x = 2; x <= N; x++) {
        for (int y = 2; y <= N; y++) {
            if (gcd(x, y) == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;

    scanf("%d", &N);
    
    int result = countConnectedPoints(N);
    printf("%d\n",result);
    
    return 0;
}
