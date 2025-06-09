#include <stdio.h>

/**
 * 已知非空二叉树 T 的结点值均为正整数，采用顺序存储方式保存，数据结构定义如下：
 * typedef struct
 * {
 * int SqBiTNode[MAX_SIZE]; // 保存二叉树结点值的数组
 * int ElemNum; // 实际占用的数组元素个数
 * } SqBiTree;
 * T 中不存在的结点在数组 SqBiTNode 中用-1 表示。
 * 请设计一个尽可能高效的算法，判定一棵采用这种方式存储的二叉树是否为二叉搜索树，若 是，则返回 true，否则，返回 false。
 */
#define false 0
#define ture 1
#define MAX_SIZE 4
typedef int bool;

struct SqBiTree
{
    int SqBiTNode[MAX_SIZE]; // 保存二叉树结点值的数组
    int ElemNum;             // 实际占用的数组元素个数
};

// 初始调用时 k 的值是 0
bool judgeInOrderBST(struct SqBiTree bt, int k, int *val)
{
    if (k < bt.ElemNum && bt.SqBiTNode[k] != -1)
    {
        if (!judgeInOrderBST(bt, 2 * k + 1, val))
        {
            return false;
        }
        if (bt.SqBiTNode[k] <= *val)
        {
            return false;
        }
        *val = bt.SqBiTNode[k];
        if (!judgeInOrderBST(bt, 2 * k + 2, val))
        {
            return false;
        }
    }
    return ture;
}

bool judgeInOrderBST(struct SqBiTree bt, int k, int *val);

int main()
{
    int val = -1;
    struct SqBiTree tree;
    int node[MAX_SIZE] = {4, 1, 3, -1};
    for (int j = 0; j < MAX_SIZE; j++)
    {
        tree.SqBiTNode[j] = node[j];
    }
    tree.ElemNum = MAX_SIZE;

    if (judgeInOrderBST(tree, 0, &val))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}