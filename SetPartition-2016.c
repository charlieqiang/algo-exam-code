#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 冒泡排序：从小到大
void bubbleSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 划分函数：返回差值 |S1 - S2|
int setPartition(int arr[], int length)
{
    bubbleSort(arr, length); // 排序

    int mid = length / 2;
    int sum1 = 0, sum2 = 0;
    int n1 = 0, n2 = 0;

    printf("A1: ");
    for (int i = 0; i < mid; i++)
    {
        printf("%d ", arr[i]);
        sum1 += arr[i];
        n1++;
    }
    printf("\n");

    printf("A2: ");
    for (int i = mid; i < length; i++)
    {
        printf("%d ", arr[i]);
        sum2 += arr[i];
        n2++;
    }
    printf("\n");

    printf("|n1 - n2| = %d\n", abs(n1 - n2));
    printf("|S1 - S2| = %d\n", abs(sum1 - sum2));

    return abs(sum1 - sum2);
}

int main()
{
    int arr[] = {5, 2, 9, 4, 7, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int diff = setPartition(arr, length);

    printf("最大和差（近似）为：%d\n", diff);

    return 0;
}