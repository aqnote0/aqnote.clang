/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/10/19 12:24:59
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

void aqnote_sort_bubble(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1])
                swap_int(array + j, array + j + 1);
        }
    }
}