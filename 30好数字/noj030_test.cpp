#include <iostream>

using namespace std;

const long long MOD = 1000000007;

// 快速幂取模
long long fastPow(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return result;
}

int countGoodNumbers(long long N) {
    // 5的幂次
    long long pow5 = N / 2;
    // 4的幂次
    long long pow4 = N / 2;

    // 如果N为奇数，需要额外乘以5
    if (N % 2 == 1) {
        pow5++;
    }

    long long result = (fastPow(5, pow5) * fastPow(4, pow4)) % MOD;

    return static_cast<int>(result);
}

int main() {
    long long N;
    cout << "请输入整数 N（1 ≤ N ≤ 10^15）：";
    cin >> N;

    int result = countGoodNumbers(N);
    cout << "长度为 " << N << " 的好数字的总数是：" << result << endl;

    return 0;
}
