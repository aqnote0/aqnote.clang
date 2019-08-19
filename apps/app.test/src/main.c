/*
 * ===========================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/24/19 19:48:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * ===========================================================================
 */
#include <stdio.h>
#include "test.h"

int main(int argc, char **argv) {

    printf("################\n");
    {
        int a = 1, b = 2;

        printf("## 1\n");
        printf("before a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);
        swap(&a, &b);
        printf("after a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);

        a = 1, b = 2;
        printf("## 2\n");
        printf("before a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);
        int *pa = &a;
        int *pb = &b;
        swap(pa, pb);
        printf("after a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);

        a = 1, b = 2;
        printf("## 3\n");
        printf("before a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);
        int *pa_1 = &a;
        int *pb_1 = &b;
        swap1(pa_1, pb_1);
        printf("after a (%p, %d), b (%p, %d)\n", (void *)&a, a, (void *)&b, b);
    }

    printf("################\n");
    {
        int result;
        int code = is_leap_year(2017, &result);
        if (code == 0) {
            if (result == 1) {
                printf("闰年\n");
            } else {
                printf("不是闰年\n");
            }
        } else {
            printf("error.\n");
        }
    }

    printf("################\n");
    {
        int year, week, day;

        int noday = 500;
        int code  = day_to_date(noday, &year, &week, &day);
        if (code == 0) {
            printf("day: %d -> year: %d, week: %d, day: %d\n", noday, year,
                   week, day);
        } else {
            printf("error.\n");
        }
    }

    printf("################\n");
    {
        int result;
        int code = max(2, 1, 3, &result);
        if (code == 0) {
            printf("max is %d\n", result);
        } else {
            printf("error.\n");
        }
    }

    return 0;
}
