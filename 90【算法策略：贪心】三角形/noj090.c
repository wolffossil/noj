#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//快排模板
void quicksort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int i = l - 1;
        int j = r + 1;
        int x = arr[(l + r) / 2];
        while (i < j)
        {
            do
            {
                i++;
            } while (arr[i] > x);
 
            do
            {
                j--;
            } while (arr[j] < x);
 
            if (i < j)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        quicksort(arr, l, j);
        quicksort(arr, j + 1, r);
    }
}



//----------------------------------------------------------------

void is_Triangle(int arr[], int n){
    for(int i=0;i<n-2;i++){
        if(arr[i]<arr[i+1]+arr[i+2]){
            printf("%d %d %d\n",arr[i+2],arr[i+1],arr[i]);
            return ;
        }
    }

    printf("-1");

}



int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    quicksort(a,0,n-1);
    is_Triangle(a,n);
}

/*
6
1 8 5 2 4 3
*/