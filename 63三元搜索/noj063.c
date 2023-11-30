#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int key;
    scanf("%d",&key);
    int left=0,right=n-1;
    int mid1,mid2;
    int result;
    while(1){
        if(key>a[right]){
            result=-1;
            break;
        }
        if(key<a[left]){
            result=-1;
            break;
        }
        mid1=left+(right-left)/3;
        mid2=right-(right-left)/3;
        if(a[mid1]==key) 
        {
            result=mid1;
            break;
        }
        if(a[mid2]==key)
        { 
            result=mid2;
            break;
        }
        if(mid1==mid2)
        {
            result=-1;
            break;
        }
        if(key<a[mid1]) right=mid1-1;
        else if(key>a[mid2]) left=mid2+1;
        else if(key>a[mid1]&&key<a[mid2]){
            left=mid1+1;
            right=mid2-1;
        }
    }
    printf("%d in [%d]",key,result);
}

/*
9
1 2 3 4 5 6 7 8 9
6
*/