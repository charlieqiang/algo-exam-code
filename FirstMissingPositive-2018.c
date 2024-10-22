#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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