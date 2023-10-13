#include <stdio.h>
int getMultiplesSum(int n) { int sum = 0;
 for (int i = 1; i < n; i++) {
 if (i % 3 == 0 || i % 5 == 0) {
 sum += i;
 } 
 }
 return sum;
}
int main() {
 int T;
 scanf("%d", &T);
 int arr[1000000];
  for (int i = 0; i < T; i++) {
int n;
 scanf("%d", &n);
 int result = getMultiplesSum(n);
 arr[i]=result;
 }
 for (int m=0;m<T;m++){
 printf("%d\n",arr[m]);
 }
 return 0;
}