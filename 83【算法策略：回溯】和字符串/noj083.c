#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
long long substrToNum(char str[], int pos, int len) {
	long long num = 0;
	for (int i = 0; i < len; ++i)
		num = num * 10 + str[pos + i] - '0';
	return num;
}
 
long long getLen(long long n) {
	int cnt = 0;
	do ++cnt, n /= 10; while(n);
	return cnt;
}
 
bool backTracking(char str[], int strLen, int begin, int len1, int len2) {
	if (begin + len1 + len2 >= strLen) return true;
	long long num1 = substrToNum(str, begin, len1);
	long long num2 = substrToNum(str, begin + len1, len2);
	long long num3 = substrToNum(str, begin + len1 + len2, getLen(num1 + num2));
    printf("%lld,%lld,%lld\n", num1, num2, num3);
	if (num1 + num2 == num3) return backTracking(str, strLen, begin + getLen(num1), getLen(num2), getLen(num3));
	return false;
}
 
void partition(char str[]) {
	int strLen = strlen(str);
	for (int i = 1; i <= strLen / 2; ++i) {
		if (backTracking (str, strLen, 0, i, i)) {
			printf("true\n");
			return;
		}
	}
	printf("false\n");
}
 
int main() {
	char str[1000] = "";
	scanf("%s", str);
	partition(str);
	return 0;
}