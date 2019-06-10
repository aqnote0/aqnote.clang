/*
 * =====================================================================================
 *
 *       Filename:  aqnote_sort.c
 *
 *    Description:  排序实现
 *
 *        Version:  1.0
 *        Created:  03/31/19 19:19:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */

#include "aqnote/algorithm/sort.h"

// inner function
void swap(int a[], int n, int m) {
    if (n == m)
        return;
    int tmp = a[n];
    a[n]    = a[m];
    a[m]    = tmp;
}

void swap_int(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}