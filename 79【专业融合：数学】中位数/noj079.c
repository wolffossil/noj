#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 计算中位数
double calculateMedian(int *array, int size) {
    // 将数组排序
    qsort(array, size, sizeof(int), compare);

    // 计算中位数
    if (size % 2 == 1) {
        return array[size / 2];
    } else {
        int middle1 = array[size / 2 - 1];
        int middle2 = array[size / 2];
        return (double)(middle1 + middle2) / 2;
    }
}

int main() {
    int input;
    int *queue = NULL;
    int size = 0;

    while (1) {
        scanf("%d", &input);

        if (input > 0) {
            size++;
            queue = (int *)realloc(queue, size * sizeof(int));
            queue[size - 1] = input;
        } 
        else if (input == 0)
        {
            double median = calculateMedian(queue, size);

            for (int i = 0; i < size; ++i) {
                printf("%d ", queue[i]);
            }
            printf("%.6lf\n", median);
        } 
        else if(input==-1)
        {
            break;
        }
    }


    return 0;
}
