#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 40001

struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Reorder a linked list in the following manner:
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * The function modifies the list in place and does not return anything.
 *
 * @param head Pointer to the head of the linked list.
 * This function reorders the linked list by first storing the nodes in an array,
 *
 * then rearranging the pointers to achieve the desired order.
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL)
    {
        // Reverse the current node's next pointer
        struct ListNode *next = curr->next;
        // and move to the next node in the original list.
        curr->next = prev;
        // Move the pointers one position ahead.
        prev = curr;
        // prev becomes the current node, and curr moves to the next node.
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    head->next = reverseList(head->next);
    reorderList(head->next);
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