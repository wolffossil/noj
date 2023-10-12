#include <stdio.h>


struct Fraction {
    int numerator;   // 分子
    int denominator; // 分母
};

// 最大公约数
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 简化
void simplify(struct Fraction *frac) {
    int common_divisor = gcd(frac->numerator, frac->denominator);
    frac->numerator /= common_divisor;
    frac->denominator /= common_divisor;
}

int main() {
    struct Fraction frac1, frac2, result;


    scanf("%d/%d", &frac1.numerator, &frac1.denominator);
    scanf("%d/%d", &frac2.numerator, &frac2.denominator);

    // 加法
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    simplify(&result);
    printf("(%d/%d)+(%d/%d)=%d/%d\n", frac1.numerator, frac1.denominator,
           frac2.numerator, frac2.denominator, result.numerator, result.denominator);

    // 减法
    result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    simplify(&result);
    printf("(%d/%d)-(%d/%d)=%d/%d\n", frac1.numerator, frac1.denominator,
           frac2.numerator, frac2.denominator, result.numerator, result.denominator);

    // 乘法
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    simplify(&result);
    printf("(%d/%d)*(%d/%d)=%d/%d\n", frac1.numerator, frac1.denominator,
           frac2.numerator, frac2.denominator, result.numerator, result.denominator);

    // 除法
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;
    simplify(&result);
    printf("(%d/%d)/(%d/%d)=%d/%d\n", frac1.numerator, frac1.denominator,
           frac2.numerator, frac2.denominator, result.numerator, result.denominator);

    return 0;
}
