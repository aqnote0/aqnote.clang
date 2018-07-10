

typedef struct _LinkedList{
    int key;
    struct _LinkedList* next;
} LinkedList;

void printLinkedList(LinkedList* node);
void invertPrint(LinkedList* node);
LinkedList* invertLinkedList(LinkedList* head);
