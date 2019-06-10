/*
 * =====================================================================================
 *
 *       Filename:  selection_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/10/19 12:26:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "aqnote/algorithm/sort.h"
#include "util.h"

void aqnote_sort_select(int a[], int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (a[k] > a[j])
                k = j;
        }
        if (k != i)
            swap_int(a + i, a + k);
    }
}