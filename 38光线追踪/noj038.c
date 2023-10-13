#include <stdio.h>

int main() {
    long long N, X;
    scanf("%lld %lld", &N, &X);

    long long totalLength = 0;

    if (X == 1 || X == N - 1) {
        // 特殊情况，p位于边缘
        totalLength = N * (N - 1) / 2;
    } else {
        long long rightDist = N - X;
        long long leftDist = X - 1;
        totalLength = X * (X - 1) / 2 + rightDist * (rightDist - 1) / 2 + leftDist;
    }

    printf("%lld\n", totalLength);

    return 0;
}
