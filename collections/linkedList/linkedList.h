

typedef struct _LinkedList{
    int key;
    struct _LinkedList* next;
} LinkedList;

void linkedList_print(LinkedList* node);
void linkedList_invertPrint(LinkedList* node);
LinkedList* linkedList_invert(LinkedList* head);
