/*
 * =====================================================================================
 *
 *       Filename:  aqnote.c
 *
 *    Description:
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
#include <stdio.h>

int swap(int *pa, int *pb) {
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;

    return 0;
}

int swap1(int *pa, int *pb) {
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;

    return 0;
}

int is_leap_year(const int year, int *result) {
    if (year % 400 == 0)
        *result = 1;
    else if (year % 100 == 0)
        *result = 0;
    else if (year % 4 == 0)
        *result = 0;

    return 0;
}

int day_to_date(const int noday, int *year, int *week, int *day) {
    *year = noday / 365;
    *week = (noday % 365) / 7;
    *day  = (noday % 365) % 7;

    return 0;
}

int max(const int num1, const int num2, const int num3, int *result) {
    *result = num1 > num2 ? num1 : num2;
    *result = *result > num3 ? *result : num3;

    return 0;
}