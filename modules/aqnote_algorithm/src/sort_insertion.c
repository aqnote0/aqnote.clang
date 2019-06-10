/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/10/19 12:25:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include "aqnote/algorithm/sort.h"

#include <stdlib.h>

void aqnote_sort_insert(int a[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = a[i];
        for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}