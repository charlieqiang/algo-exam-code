#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 40001

struct ListNode
{
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    struct ListNode *vec[MAXV];
    struct ListNode *node = head;
    int n = 0;
    while (node != NULL)
    {
        vec[n++] = node;
        node = node->next;
    }
    int i = 0, j = n - 1;
    while (i < j)
    {
        vec[i]->next = vec[j];
        i++;
        if (i == j)
        {
            break;
        }
        vec[j]->next = vec[i];
        j--;
    }
    vec[i]->next = NULL;
}

int main()
{
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 4;
    node4->next = NULL;
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 3;
    node3->next = node4;
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 2;
    node2->next = node3;
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = 1;
    node->next = node2;

    reorderList(node);

    while (node != NULL)
    {
        printf("%d\n", node->val);
        node = node->next;
    }

    return (0);
}