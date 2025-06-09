#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 给定一个含n(n≥1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
 * 例如,数组{-5, 3, 2, 3}中未出现的最小正整数是1；数组{1, 2, 3}中未出现的最小正整数是4。
 */

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int firstMissingPositive(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr, i, j);
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {-5, 3, 2, 3};
    printf("%d", firstMissingPositive(arr, 4));
}