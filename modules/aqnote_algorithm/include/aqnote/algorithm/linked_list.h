/*
 * =====================================================================================
 *
 *       Filename:  aqnote_linked_list.h
 *
 *    Description: 链表头文件
 *
 *        Version:  1.0
 *        Created:  03/31/19 19:14:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef _AQNOTE_ALGORITHM_LINKED_LIST_H
#define _AQNOTE_ALGORITHM_LINKED_LIST_H

typedef struct _aqnote_linked_list {
    int                         key;
    struct _aqnote_linked_list *next;
} aqnote_linked_list;

aqnote_linked_list *aqnote_linked_list_init(int n);
aqnote_linked_list *aqnote_linked_list_invert(aqnote_linked_list *head);

void aqnote_linked_list_print(aqnote_linked_list *node);
void aqnote_linked_list_invert_print(aqnote_linked_list *node);

#endif