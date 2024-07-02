#include <stdio.h>

#define false 0
#define ture 1
typedef int bool;

// 初始调用时 k 的值是 0
bool judgeInOrderBST(SqBiTree bt, int k, int *val)
{
    if (k < bt.ElemNum && bt.SqBiTNode[k] ! = -1)
    {
        if (!judgeInOrderBST(bt, 2 * k + 1, val))
            return false;
        if (bt.SqBiTNode[k] <= *val)
            return false;
        *val = bt.SqBiTNode[k];
        if (!judgeInOrderBST(bt, 2 * k + 1, val))
            return false;
    }
    return ture;
}

int main()
{

    return 0;
}