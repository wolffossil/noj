#include <stdio.h>
#include <stdbool.h>

int m, n;
int d;
int minOperations = -1;

// 记录已经访问过的状态
bool visited[101][101] = {false};

void dfs(int x, int y, int steps) {
    if (steps >= minOperations && minOperations != -1) {
        return; // 如果已经找到更小的操作数，就不再搜索
    }
    
    if (x == d || y == d) {
        if (minOperations == -1 || steps < minOperations) {
            minOperations = steps; // 更新最小操作数
        }
        return;
    }
    
    if (visited[x][y]) {
        return; // 已经访问过这个状态，无需继续搜索
    }
    
    visited[x][y] = true;
    
    // 倒空一个杯子
    dfs(0, y, steps + 1);
    dfs(x, 0, steps + 1);
    
    // 装满一个杯子
    dfs(m, y, steps + 1);
    dfs(x, n, steps + 1);
    
    // 将水从一个杯子倒入另一个杯子
    int pour = x + y;
    int new_x = (pour > n) ? (pour - n) : 0;
    int new_y = (pour > n) ? n : pour;
    dfs(new_x, new_y, steps + 1);
    
    pour = x + y;
    new_x = (pour > m) ? m : pour;
    new_y = (pour > m) ? (pour - m) : 0;
    dfs(new_x, new_y, steps + 1);
    
    visited[x][y] = false; // 恢复状态以供其他路径使用
}

int main() {
    printf("请输入两个杯子的容积（m和n，0 < m < n）：");
    scanf("%d %d", &m, &n);
    
    printf("请输入目标水量d（d < n）：");
    scanf("%d", &d);
    
    dfs(0, 0, 0);
    
    if (minOperations == -1) {
        printf("无法得到%d升水\n", d);
    } else {
        printf("得到%d升水所需要的最小操作数为：%d\n", d, minOperations);
    }
    
    return 0;
}
