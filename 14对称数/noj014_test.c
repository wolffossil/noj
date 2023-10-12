#include <stdio.h>

int isSymmetric(int num) {
    int originalNum = num;
    int rotatedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        if (digit == 6) {
            rotatedNum = rotatedNum * 10 + 9; // 将6替换为9
        } else if (digit == 9) {
            rotatedNum = rotatedNum * 10 + 6; // 将9替换为6
        } else if (digit == 1) {
            rotatedNum = rotatedNum * 10 + 1;
        } else if (digit == 8) {
            rotatedNum = rotatedNum * 10 + 8;
        } else if (digit == 0) {
            rotatedNum = rotatedNum * 10 + 0;
        }else {
            return 0; // 如果包含其他数字，则不是对称数
        }
        num /= 10;
    }

    return rotatedNum == originalNum; // 判断反转后的数是否与原数相等
}


int main() {
    int num;
    scanf("%d", &num);

    if (isSymmetric(num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
