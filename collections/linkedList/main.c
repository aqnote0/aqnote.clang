
#include <stdlib.h>
#include <stdio.h>
#include "com.aqnote.linkedList.h"

LinkedList* linkedList_init(int n)
{
    int i;
    LinkedList *head, *node;
    head = (LinkedList*)malloc(sizeof(LinkedList));
    head->key = 1;
    head->next = NULL;
    for (i = n; i > 1; i--)
    {
        node = (LinkedList*)malloc(sizeof(LinkedList));
        node->key = i;
        node->next = head->next;
        head->next = node;
    }

    return head;
}

int main()
{
    LinkedList* head;
    head = linkedList_init(16);
    printf("LinkedList print:\n");
    linkedList_print(head);

    printf("LinkedList invertPrint:\n");
    linkedList_invertPrint(head);
    printf("\n");

    printf("LinkedList invert:\n");
    head = linkedList_invert(head);
    linkedList_print(head);

    return 0;
}
