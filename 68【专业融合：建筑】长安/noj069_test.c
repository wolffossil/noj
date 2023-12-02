#include <stdio.h>

int countPaths(int bx, int by, int px, int py) {
    if (bx < 0 || by < 0 || px < 0 || py < 0) {
        return 0;
    }

    // 创建一个动态规划数组
    int dp[bx + 1][by + 1];
    
    // 初始化数组
    for (int i = 0; i <= bx; ++i) {
        for (int j = 0; j <= by; ++j) {
            dp[i][j] = 0;
        }
    }

    // 设置起点
    dp[0][0] = 1;

    // 计算路径数
    for (int i = 0; i <= bx; ++i) {
        for (int j = 0; j <= by; ++j) {
            // 如果当前坐标是P点，则跳过
            if (i == px && j == py) {
                continue;
            }

            // 计算当前坐标的路径数
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[bx][by];
}

int main() {
    int bx, by, px, py;

    // 输入坐标值
    while (scanf("%d%d%d%d", &bx, &by, &px, &py) != EOF) {
        if (bx ==0 && by ==0 && px == 0 && py == 0) {
            break;
        }

        // 计算路径数并输出
        int result = countPaths(bx, by, px, py);
        printf("%d\n", result);
    }

    return 0;
}
