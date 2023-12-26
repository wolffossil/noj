#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//快排模板
void quicksort(char arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int i = l - 1;
        int j = r + 1;
        char x = arr[(l + r) / 2];
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
                char tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        quicksort(arr, l, j);
        quicksort(arr, j + 1, r);
    }
}



//----------------------------------------------------------------

void swap(char arr[],int l,int r){
    for(int i=l;i<(r-l+1)/2+l;i++){
        char tmp=arr[i];
        int x=r-1-(i-l);
        arr[i]=arr[x];
        arr[x]=tmp;
    }
}

int main(){
    char str[1000];
    scanf("%s", str);
    int n=strlen(str);
    quicksort(str, 0,n/2-1);
    int right_s=n%2?n/2+1:n/2;
    swap(str,right_s,n);
    printf("%s\n",str);
}

/*
abcdefX181292
*/