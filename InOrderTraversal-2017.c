#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 10

struct BTree
{
    char data[MAXV];
    struct BTree *left, *right;
};

void inOrderTraversal(struct BTree *node, int deep)
{
    if (node == NULL)
    {
        return;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        printf("%s", node->data);
    }
    else
    {
        if (deep > 1)
        {
            printf("(");
        }
        inOrderTraversal(node->left, deep + 1);
        printf("%s", node->data);
        inOrderTraversal(node->right, deep + 1);
        if (deep > 1)
        {
            printf(")");
        }
    }
}

int main()
{
    struct BTree *NodeC = (struct BTree *)malloc(sizeof(struct BTree));
    strcpy(NodeC->data, "-");
    NodeC->left = NULL;
    NodeC->right = NULL;
    struct BTree *nodeA = (struct BTree *)malloc(sizeof(struct BTree));
    strcpy(nodeA->data, "a");
    nodeA->left = NodeC;
    nodeA->right = NULL;
    struct BTree *nodeB = (struct BTree *)malloc(sizeof(struct BTree));
    strcpy(nodeB->data, "b");
    nodeB->left = NULL;
    nodeB->right = NULL;
    struct BTree *head = (struct BTree *)malloc(sizeof(struct BTree));
    strcpy(head->data, "*");
    head->left = nodeA;
    head->right = nodeB;

    inOrderTraversal(head, 1);
    return 0;
}