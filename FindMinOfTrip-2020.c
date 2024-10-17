#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 0x7fffffff

int getAbs(int num)
{
    return num < 0 ? -num : num;
}

int findMinOfTrip(int A[], int B[], int C[], int lenA, int lenB, int lenC)
{
    int min = MAXV;
    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            for (int k = 0; k < lenC; k++)
            {
                int temp = getAbs(A[i] - B[j]) + getAbs(B[j] - C[k]) + getAbs(C[k] - A[i]);
                if (min > temp)
                {
                    min = temp;
                }
            }
        }
    }

    return min;
}

int main()
{

    int A[] = {-1, 0, 9};
    int B[] = {-25, -10, 10, 11};
    int C[] = {2, 9, 17, 30, 41};
    int lenA = sizeof(A) / sizeof(A[0]);
    int lenB = sizeof(B) / sizeof(B[0]);
    int lenC = sizeof(C) / sizeof(C[0]);
    int res = findMinOfTrip(A, B, C, lenA, lenB, lenC);
    printf("%d\n", res);
    return (0);
}