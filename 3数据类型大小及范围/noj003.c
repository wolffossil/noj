#include <stdio.h>
#include <limits.h>

int main() {
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%zu,%d,%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
            break;
        case 2:
            printf("%zu,%d,%u\n", sizeof(unsigned char), 0, UCHAR_MAX);
            break;
        case 3:
            printf("%zu,%d,%d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
            break;
        case 4:
            printf("%zu,%d,%u\n", sizeof(unsigned short), 0, USHRT_MAX);
            break;
        case 5:
            printf("%zu,%d,%d\n", sizeof(int), INT_MIN, INT_MAX);
            break;
        case 6:
            printf("%zu,%u,%u\n", sizeof(unsigned int), 0, UINT_MAX);
            break;
        case 7:
            //printf("%zu,%d,%d\n", sizeof(int), INT_MIN, INT_MAX);
            printf("%zu,%ld,%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
            break;
        case 8:
            printf("%zu,%u,%lu\n", sizeof(unsigned long), 0UL, ULONG_MAX);
            //printf("%zu,%u,%u\n", sizeof(unsigned int), 0, UINT_MAX);
            break;
        case 9:
            printf("%zu,%lld,%lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
            break;
        case 10:
            printf("%zu,%u,%llu\n", sizeof(unsigned long long), 0ULL, ULLONG_MAX);
            break;
        default:
            printf("无效的编号\n");
            break;
    }

    return 0;
}
