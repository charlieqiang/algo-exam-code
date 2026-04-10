#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MINV 0xffffffff

/**
 * 设有两个长度均为 n 的一维整型数组 A 和 res，对数组 A 中的每个元素 A[i]，计算 A[i] 与 A[j](0 ≤ i ≤ j ≤ n-1) 乘积的最大值，并将其保存到 res[i]中。
 * 例如，若 A[i] = {1, 4, -9, 6}，则得到 res[i] = {6, 24, 81, 36}。现给定数组 A，请设计一个时间和空间上尽可能高效的算法 calMulMax，求 res 中各元素的值。
 * 函数原型为：void calMulMax(int A[], int res[], int n)
 */
void calMulMax(int arr[], int res[], int n) {
    for(int i=0;i<n;i++){
        int max = MINV;
        for(int j=0;j<n;j++){
            if (max < arr[i] * arr[j]) {
                max = arr[i] * arr[j];
            }
        }
        res[i] = max;
    }
}

int main()
{
    int arr[] = {1, 4, -9, 6};
    int res[4];
    calMulMax(arr, res, 4);
    for (int i=0;i<4;i++){
        printf("%d\n", res[i]);
    }
    return 0;
}