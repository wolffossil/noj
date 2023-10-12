#include <stdio.h>


long long solve(long long n){
    long long result = 0;
    while(n>0){
        result = result + n%10;
        n=n/10;
    }
    return result;
}

int main(){
  long long  n;
  scanf("%lld", &n);
  long long  num=0;
  while(n>0){
    n=n-solve(n);
    num++;
  }
  printf("%lld\n", num);

}