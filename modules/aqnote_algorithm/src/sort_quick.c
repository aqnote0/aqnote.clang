/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/19 12:27:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include "aqnote/algorithm/linked_list.h"

#include <stdlib.h>


void aqnote_sort_quick(int a[], int n) {
    int i;
    int last = 0;
    if (n < 2)
        return;
    swap(a, 0, n / 2);
    for (i = 1; i < n; i++) {
        if (a[i] < a[0]) {
            swap(a, ++last, i);
        }
    }
    swap(a, 0, last);
    aqnote_sort_quick(a, last);
    aqnote_sort_quick(a + last + 1, n - last - 1);
}