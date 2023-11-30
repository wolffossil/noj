#include <stdio.h>

int main(){
      int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    for(int j=0; j<n-1; j++){
        int item= a[j];
        int pos= j;

        for(int i=j+1; i<n;i++){
            if(a[i]<item) pos++;
        }

        if(pos==j) continue;
        int tmp=a[pos];
        a[pos]=item;
        item=tmp;

        while(pos!=j){
            pos=j;
            for(int k=j+1;k<n;k++){
                if (a[k] < item) {
                    pos++;
                }
            }
            
             while (item == a[pos]) {
                pos++;
            }


            int temp = a[pos];
            a[pos] = item;
            item = temp;
        }

    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
        
}
/*
8
1 8 3 9 10 10 2 4
*/