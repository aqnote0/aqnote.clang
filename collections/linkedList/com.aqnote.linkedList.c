// �������ݽṹ

#include "com.aqnote.linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void linkedList_print(LinkedList* node)
{
    while (node)
    {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}

void linkedList_invertPrint(LinkedList* node)
{
    if (node)
    {
        linkedList_invertPrint(node->next);
        printf("%d ", node->key);
    }
}

LinkedList* linkedList_invert(LinkedList* head)
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


