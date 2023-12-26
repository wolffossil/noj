#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct flight{
    char name[100];
    int x,y;
};

double solve(int x1,int y1,int x2,int y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}



int main(){

    int n;
    scanf("%d", &n);
    struct flight a[n];
    for(int i=0;i<n;i++){
        scanf("%s %d %d",a[i].name,&a[i].x,&a[i].y);
    }
    double min=9999999;
    char flight1[100];
    char flight2[100];
     for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = solve(a[i].x, a[i].y, a[j].x, a[j].y);
            if (distance < min) {
                min = distance;
                snprintf(flight1, sizeof(flight1), "%s", a[i].name);
                snprintf(flight2, sizeof(flight2), "%s", a[j].name);
            }
        }
    }

    // 输出结果
    printf("%s-%s %.4lf\n", flight1, flight2, min);

    return 0;

    
}

/*
6
UAO57 2 3
AA044 12 30
BA1534 40 50
DL262 5 1
AF001 12 10
SK837 3 4
*/
