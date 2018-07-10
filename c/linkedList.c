// 链表数据结构

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void printLinkedList(LinkedList* node)
{
    while (node)
    {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}

void invertPrint(LinkedList* node)
{
    if (node)
    {
        invertPrint(node->next);
        printf("%d ", node->key);
    }
}

LinkedList* invertLinkedList(LinkedList* head)
{
    LinkedList *pre, *cur, *temp;
    pre = head;
    cur = pre->next;
    pre->next = NULL;
    while (cur)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}


