
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

LinkedList* initLinkedList(int n)
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
    head = initLinkedList(16);
    printf("print LinkedList:\n");
    printLinkedList(head);

    printf("invertPrint LinkedList:\n");
    invertPrint(head);
    printf("\n");

    printf("invert LinkedList:\n");
    head = invertLinkedList(head);
    printLinkedList(head);

    return 0;
}
