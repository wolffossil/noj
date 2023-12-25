#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char str[MAX_LEN];
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] == 'm' || str[i] == 'w') {
            printf("0\n");
            return 0;
        }
    }

    long long dp[MAX_LEN];
    dp[0] = 1;
    dp[1] = 1;

    /*
    动态规划过程:
    以nn为例子，dp[i]代表前i个字符串的总可能性，注意空字符串也算一种可能性
    识别到"nn"时有两种情况选择，一种是保持nn,此时要单独看待input[1],也就是
    第2个n，此时的字符串可能性即为dp[1];另一种是转换为w,此时字符串的可能性为
    dp[0]，也就是空字符串的可能性。
    */
    for (int i = 1; i < len; ++i) {
        dp[i + 1] = dp[i];
        if ((str[i] == 'n' && str[i - 1] == 'n') || (str[i] == 'u' && str[i - 1] == 'u')) {
            dp[i + 1] += dp[i - 1];
        }
    }

    printf("%lld\n", dp[len]);

    return 0;
}
