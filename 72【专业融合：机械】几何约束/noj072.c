#include <stdio.h>
#include <math.h>


struct Point {
    double x, y;
};

struct Segment {
    struct Point start, end;
    int index;  // 线段的索引号
};

// 判断两线段是否相交
int doIntersect(struct Segment s1, struct Segment s2) {
    double x1 = s1.start.x, y1 = s1.start.y;
    double x2 = s1.end.x, y2 = s1.end.y;
    double x3 = s2.start.x, y3 = s2.start.y;
    double x4 = s2.end.x, y4 = s2.end.y;

    double a1 = y2 - y1;
    double b1 = x1 - x2;
    double c1 = a1 * x1 + b1 * y1;

    double a2 = y4 - y3;
    double b2 = x3 - x4;
    double c2 = a2 * x3 + b2 * y3;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        // 平行线段
        return 0;
    } else {
        double intersectX = (b2 * c1 - b1 * c2) / determinant;
        double intersectY = (a1 * c2 - a2 * c1) / determinant;

        // 检查交点是否在线段内
        if (intersectX >= fmin(x1, x2) && intersectX <= fmax(x1, x2) &&
            intersectX >= fmin(x3, x4) && intersectX <= fmax(x3, x4) &&
            intersectY >= fmin(y1, y2) && intersectY <= fmax(y1, y2) &&
            intersectY >= fmin(y3, y4) && intersectY <= fmax(y3, y4)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Segment segments[n];

    // 读取线段信息
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf %lf", &segments[i].start.x, &segments[i].start.y,
              &segments[i].end.x, &segments[i].end.y);
        segments[i].index = i + 1;
    }

    int intersectionCount = 0;

    // 检查线段相交
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (doIntersect(segments[i], segments[j])) {
                printf("X: #%d #%d\n", segments[i].index, segments[j].index);
                intersectionCount++;
            }
        }
    }

    // 输出相交的总数
    printf("n=%d\n", intersectionCount);

    return 0;
}


/*
5
1 5 4 5
2 5 10 1
3 2 10 3
6 4 9 4
7 1 8 1
*/