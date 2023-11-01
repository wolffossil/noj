#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int non_zero_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                non_zero_count++;
            }
        }
    }

    if (non_zero_count <= 0.05 * n * m || non_zero_count == n || non_zero_count == m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


/*
4 4
5 0 0 0
0 8 0 0
0 0 3 0
0 6 0 0
*/
