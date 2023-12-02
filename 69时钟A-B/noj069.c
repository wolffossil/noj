#include <stdio.h>
#include <time.h>

int main() {

    int yearA, monthA, dayA;
    scanf("%d %d %d", &yearA, &monthA, &dayA);

    int yearB, monthB, dayB;
    scanf("%d %d %d", &yearB, &monthB, &dayB);

    // 构建tm结构体表示A和B的日期时间
    struct tm timeA = {0};
    struct tm timeB = {0};

    timeA.tm_year = yearA - 1900; 
    timeA.tm_mon = monthA - 1;    
    timeA.tm_mday = dayA;

    timeB.tm_year = yearB - 1900;
    timeB.tm_mon = monthB - 1;
    timeB.tm_mday = dayB;

 
    time_t timestampA = mktime(&timeA);
    time_t timestampB = mktime(&timeB);

 
    double difference = difftime(timestampA, timestampB);


    printf("%.6lf\n", difference);

    return 0;
}


/*
2021 1 2
2021 1 1
*/