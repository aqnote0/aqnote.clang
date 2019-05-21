/*
 * =====================================================================================
 *
 *       Filename:  aqnote_linked_list.c
 *
 *    Description:  链表实现
 *
 *        Version:  1.0
 *        Created:  03/31/19 19:17:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */

#include "aqnote/algorithm/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

aqnote_linked_list *aqnote_linked_list_init( int n ) {
    int                 i;
    aqnote_linked_list *head, *node;
    head       = (aqnote_linked_list *)malloc( sizeof( aqnote_linked_list ) );
    head->key  = 1;
    head->next = NULL;
    for ( i = n; i > 1; i-- ) {
        node       = (aqnote_linked_list *)malloc( sizeof( aqnote_linked_list ) );
        node->key  = i;
        node->next = head->next;
        head->next = node;
    }

    return head;
}

void aqnote_linked_list_print( aqnote_linked_list *node ) {
    while ( node ) {
        printf( "%d ", node->key );
        node = node->next;
    }
    printf( "\n" );
}

void aqnote_linked_list_invert_print( aqnote_linked_list *node ) {
    if ( node ) {
        aqnote_linked_list_invert_print( node->next );
        printf( "%d ", node->key );
    }
}

aqnote_linked_list *aqnote_linked_list_invert( aqnote_linked_list *head ) {
    aqnote_linked_list *pre, *cur, *temp;
    pre       = head;
    cur       = pre->next;
    pre->next = NULL;
    while ( cur ) {
        temp      = cur->next;
        cur->next = pre;
        pre       = cur;
        cur       = temp;
    }
    return pre;
}
