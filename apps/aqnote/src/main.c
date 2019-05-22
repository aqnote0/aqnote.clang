/*
 * =====================================================================================
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
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>

int  index = 0;
void recurse() {
    printf("%d, %d\n", index, index);
    if (index == 1000000)
        return;
    index++;
    recurse();
}

int  index_branch2 = 0;
void recurse_branch2() {
    printf("%d, %d, %d\n", index_branch2, (int)powl(index_branch2, 1.0 / 2),
           (int)sqrt(index_branch2));
    if (index_branch2 == 1000000)
        return;
    index_branch2++;
    recurse_branch2();
    recurse_branch2();
}

int  index_branch3 = 0;
void recurse_branch3() {
    printf("%d, %d, %d\n", index_branch3, (int)powl(index_branch3, 1.0 / 3),
           (int)cbrt(index_branch3));
    if (index_branch3 == 1000000)
        return;
    index_branch3++;
    recurse_branch3();
    recurse_branch3();
}

int main(int argc, char **argv) {

    // recurse();
    // recurse_branch2();
    recurse_branch3();

    return 0;
}
