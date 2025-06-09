#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file FindMinOfTrip-2020.c
 * @brief 求三个数组中任意三个元素的绝对差之和的最小值
 * 定义三元组(a,b,c)(其中a,b,c均为正数)的距离D=|a-b|+|b-c|+|c-a|。
 * 给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中。
 * 设计一个尽可能高效的算法,计算并输出所有可能的三元组(a,b, c) (a∈S1, b ∈S2, c ∈S3)中的最小距离。
 * 例如 S1={-1,0,9}，S2 = {-25,-10,10, 11}，S3 ={2,9,17,30, 41}，则最小距离为2，相应的三元组为(9,10,9)。
 */

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