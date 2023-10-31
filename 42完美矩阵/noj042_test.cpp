#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> matrix;

// 检查子矩阵是否是完美矩阵
bool isPerfectMatrix(vector<vector<int>>& subMatrix) {
    int zeros = 0, ones = 0;
    int r = subMatrix.size(), c = subMatrix[0].size();

    // 检查四边是否都是1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                if (subMatrix[i][j] != 1) {
                    return false;
                }
            } else {
                if (subMatrix[i][j] == 0) {
                    zeros++;
                } else {
                    ones++;
                }
            }
        }
    }

    // 检查内部0和1的个数差
    return abs(zeros - ones) <= 1;
}

// DFS遍历子矩阵
int countPerfectMatrices(int x1, int y1, int x2, int y2) {
    if( x2-x1==1&&y2-y1==1){
        if(matrix[x1][y1]==1&&matrix[x1][y2]==1&&matrix[x2][y1]==1&&matrix[x2][y2]==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (x2==x1 || y2==y1) {
        return 0;  // 子矩阵太小，不可能是完美矩阵
    }

    int count = 0;

    vector<vector<int>> subMatrix(x2 - x1 + 1, vector<int>(y2 - y1 + 1));

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            subMatrix[i - x1][j - y1] = matrix[i][j];
        }
    }

    if (isPerfectMatrix(subMatrix)) {
        count++;
    }

    // 分割子矩阵并继续遍历
    count += countPerfectMatrices(x1 + 1, y1, x2, y2);
    count += countPerfectMatrices(x1,y1+1,x2,y2);
    count += countPerfectMatrices(x1,y1,x2-1,y2);
    count += countPerfectMatrices(x1,y1,x2,y2-1);

    return count;
}

int main() {
    cin >> n >> m;
    matrix.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int totalPerfectMatrices = countPerfectMatrices(0, 0, n - 1, m - 1);
    cout << totalPerfectMatrices << endl;

    return 0;
}


/*
4 4
1 1 1 1
1 0 1 1 
1 1 0 1
1 1 1 1

5 5
1 0 1 1 1
1 0 1 0 1
1 1 0 1 1
1 0 0 1 1
1 1 1 1 1

2 2 
1 1 
1 1

*/