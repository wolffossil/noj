#include <stdio.h>
#include <time.h>

#include <limits.h>

#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


void quickSort(long long arr[], long long left, long long right) {
	if (left >= right) return;
	srand(time(NULL));
	long long idx = rand() % (left - right) + left;
	long long flag = arr[idx], head = left - 1, tail = right + 1;
	while (head < tail) {
		do head++; while(arr[head] < flag);
		do tail--; while(arr[tail] > flag);
		if (head < tail) {
			long long tmp = arr[head];
			arr[head] = arr[tail];
			arr[tail] = tmp;
		}
	}
	quickSort(arr, left, tail);
	quickSort(arr, tail + 1, right);
}



int main() {
    long long  n;
    scanf("%lld", &n);

    long long  arr[n];

    // 输入序列
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    quickSort(arr,0,n-1);

    // 初始化动态规划数组
    int dp[n];
    dp[0] = arr[0];
    int MAX=0;

    // 动态规划递推
    for (int i = 1; i < n; i++) {

        /*
        当arr[i]和前一个数字相等时，判断正负数，即相加后是否变小即可，选大的填入
        */
        if(arr[i]==arr[i-1])
        {
            dp[i]=max(dp[i-1],dp[i-1]+arr[i]);
        }
        /*
        存在111112333334555555这种情况
        */
        else{
            int j=i-1;
            while(j>=0&&arr[j]==arr[i]-1) j--;
            if(j>=0){
                dp[i]=arr[i]+dp[j];
            }
            else
            {
                dp[i]=arr[i];
            }
        }
        MAX=max(MAX,dp[i]);
    }

    printf("%d\n", MAX);

    return 0;
}
