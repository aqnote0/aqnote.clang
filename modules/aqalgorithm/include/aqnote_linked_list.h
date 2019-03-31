

typedef struct _aqnote_linked_list
{
    int key;
    struct _aqnote_linked_list *next;
} aqnote_linked_list;

aqnote_linked_list *aqnote_linked_list_init(int n);
aqnote_linked_list *aqnote_linked_list_invert(aqnote_linked_list *head);

void aqnote_linked_list_print(aqnote_linked_list *node);
void aqnote_linked_list_invert_print(aqnote_linked_list *node);
