#include <stdio.h>
#include <math.h>
#define scanf scanf_s
double calculateSpeed(double temperature, double pressure, int elevation, int runway, int weight, int flaps, int wet) {
    // 检查输入是否在有效范围内
    if (flaps != 1 && flaps != 5 && flaps != 15) {
        return -1;
    }

    if (weight < 41413 || weight > 65000 || runway <= 6900) {
        return -1;
    }
    // 计算温度档和气压档
    int tempRange = floor(temperature / 10);
    int pressureRange = ceil(pressure);
    // 检查操纵参考表是否存在
    if (tempRange < 0 || tempRange > 7 || pressureRange < 0 || pressureRange > 9) {
        return -1;
    }
    // 根据温度档和气压档查找操纵参考值
    char referenceTable[8][10] = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K'},
        {'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
        {'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B'},
        {'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M'},
        {'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}
    };
    char reference = referenceTable[tempRange][pressureRange];
    // 检查操纵参考表是否存在V1、Vr和V2
    if (reference != 'A' && reference != 'B' && reference != 'C' && reference != 'D' && reference != 'E') {
        return -1;
    }
    // 根据襟翼位置、起飞重量和操纵参考值查找V1、Vr和V2
    int speedTable[3][5] = {
        {117, 126, 134, 142, 151},
        {122, 131, 139, 147, 156},
        {127, 136, 145, 153, 162}
    };
    int speedIndex = (flaps - 1) / 7;
    int* speedRow = speedTable[speedIndex];
    int v1 = speedRow[weight / 13000];
    int vr = speedRow[weight / 13000] + 11;
    int v2 = speedRow[weight / 13000] + 18;
    // 如果是湿跑道，根据跑道长度和襟翼位置查找折扣值
    if (wet == 1) {
        int discountTable[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
        int discountIndex = (flaps - 1) / 7;
        int* discountRow = discountTable[discountIndex];
        int discount = discountRow[runway / 1000];
        v1 -= discount;
    }
    printf("V1=%dkts Vr=%dkts V2=%dkts\n", v1, vr, v2);
    return 0;
}
int main() {
    double temperature, pressure;
    int elevation, runway, weight, flaps, wet;
    scanf("%lf %lf", &temperature, &pressure);
    scanf("%d %d %d %d %d", &elevation, &runway, &weight, &flaps, &wet);
    int result = calculateSpeed(temperature, pressure, elevation, runway, weight, flaps, wet);
    if (result == -1) {
        printf("Flight not possible!\n");
    }
    return 0;
}
