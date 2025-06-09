#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 已知由n(n>=2)个正整数构成的集合 A={ak|0<=k<n}，将其划分为两个不相交的子集A1和 A2, 元素个数分别是 n1 和 n2，A1和 A2中元素之和分别为S1和 S2。
 * 设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大。
 */

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

    // 向下取整
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
    int arr[] = {5, 2, 9, 4, 7, 1, 8, 3, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    int diff = setPartition(arr, length);

    printf("最大和差（近似）为：%d\n", diff);

    return 0;
}