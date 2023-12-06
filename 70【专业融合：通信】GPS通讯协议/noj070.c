#include <stdio.h>
#include <string.h>

// 函数：计算异或校验和
unsigned char calculateChecksum(const char *sentence) {
    unsigned char checksum = 0;
    while (*sentence) {
        checksum ^= *sentence++;
    }
    return checksum;
}

// 函数：将UTC时间转换为北京时间
void convertToBeijingTime(char *utcTime, char *beijingTime) {
    int hour, minute, second;
    sscanf(utcTime, "%2d%2d%2d", &hour, &minute, &second);
    hour += 8;  // 北京时间比UTC时间多8小时
    sprintf(beijingTime, "%02d:%02d:%02d", hour, minute, second);
}

int main() {
    char sentence[256];

    while (1) {
        // 读取一行输入
        fgets(sentence, sizeof(sentence), stdin);

        // 去除换行符
        strtok(sentence, "\n");

        // 判断是否为结束
        if (strcmp(sentence, "END") == 0) {
            break;
        }

        // 判断是否为GPRMC语句
        if (strncmp(sentence, "$GPRMC,", 7) == 0) {
            // 提取校验和部分
            char *asterisk = strchr(sentence, '*');
            if (asterisk != NULL) {
                // 计算校验和
                unsigned char checksum = calculateChecksum(sentence + 1);
                // 获取语句中的校验和
                unsigned char sentenceChecksum;
                sscanf(asterisk + 1, "%2hhx", &sentenceChecksum);

                // 判断校验和是否正确
                if (checksum == sentenceChecksum) {
                    // 提取UTC时间字段
                    char utcTime[10];
                    strncpy(utcTime, sentence + 7, 9);
                    utcTime[9] = '\0';

                    // 转换为北京时间并输出
                    char beijingTime[9];
                    convertToBeijingTime(utcTime, beijingTime);
                    printf("%s\n", beijingTime);
                } else {
                    printf("error\n");
                }
            }
        }
    }

    return 0;
}
