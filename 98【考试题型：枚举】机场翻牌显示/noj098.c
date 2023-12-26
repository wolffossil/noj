#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    char str1[10];
    char str2[10];
    int sum=0;
    for(int i=0;i<6;i++){
        if(i<=1){
            sum+=(str2[i]-str1[i]+26)%26;

        }
        else {
            sum+=(str2[i]-str1[i]+10)%10;
        }

    }
    printf("%d\n",sum);

}

/*
MU2103
CA8326
*/