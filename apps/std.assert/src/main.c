/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  assert.h api use case
 *
 *        Version:  1.0
 *        Created:  03/31/19 14:13:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include <assert.h>
#include <stdlib.h>

#define NODEBUG

/**
 * 运行时判定表达式是否正确，如果不正确直接退出
 */
int test_assert() {
    assert(1.0 > 0.0);
    assert(1);
    assert(1.0 < 0.0);
    assert(1);

    return 0;
}

/**
 * 编译时判定表达式是否正确
 */
int test_static_assert() {
    static_assert(1.0 > 0.0, "1.0 <= 0.0");
    static_assert(1 + 2 == 3, "1 + 2 <> 3");
    static_assert(sizeof(int) > sizeof(char), "sizeof int is more than char");
    static_assert(1, "1 is TRUE");

    return 0;
}

int main(int argc, char **argv) {
    test_assert();
    test_static_assert();

    return EXIT_SUCCESS;
}
