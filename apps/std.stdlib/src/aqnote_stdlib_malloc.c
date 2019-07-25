/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  检查内存错误实例
 *
 *        Version:  1.0
 *        Created:  08/30/2018 06:23:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>,
 *   Organization:
 *
 * =====================================================================================
 */
#include "aqnote_stdlib.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////
// TC_1: 正常内存分配TC
// - 分配一个 10 byte 空间的 char数组
// - 分配一个 10 * 4 byte 空间的 int数组
//////////////////////////////////////////////////////////////////////////////
void test_memory_malloc1() {
    printf("\n////////////////////////////////\n");
    printf("%s\n", __func__);
    printf("////////////////////////////////\n\n");

    char *sdata = malloc(10 * sizeof(char));
    for (int i = 0; i < 10; i++)
        sdata[i] = (char)(i + '0');

    for (int i = 0; i < 10; i++)
        printf("%c ", sdata[i]);
    printf("\n");

    printf("%s\n", sdata);
    free(sdata);

    int *idata = malloc(10 * sizeof(*idata));
    for (int i = 0; i < 10; i++)
        idata[i] = i * i;

    for (int i = 0; i < 10; i++)
        printf("%d ", idata[i]);
    printf("\n");
    free(idata);

    int *p1 = malloc(10 * sizeof(int));
    free(p1);

    int *p2 = calloc(10, sizeof(int));
    // 打印指针的地址、指针的内容（指针指向的内存地址）
    // p The argument shall be a pointer to void.
    // The value of the pointer is converted to a sequence of printing
    // characters, in an implementation-defined manner.
    printf("p2 address=%p, value=%p, isnull=%s\n", (void *)&p2, p2,
           (p2 == NULL) ? "TRUE" : "FALSE");
    int *p3 = realloc(
        p2, pow(2, 48)); // 分配 $2^32$=4G $2^33$=8G $2^34$=16G $2^48$=256T
    printf("p2 address=%p, value=%p, isnull=%s\n", (void *)&p2, p2,
           (p2 == NULL) ? "TRUE" : "FALSE");
    printf("p3 address=%p, value=%p, isnull=%s\n", (void *)&p3, p3,
           (p3 == NULL) ? "TRUE" : "FALSE");
    if (p3) // p3 not null means p2 was freed by realloc
    {
        printf("enter p3\n");
        free(p3);
    } else // p3 null means p2 was not freed
    {
        printf("enter p2\n");
        free(p2);
    }
}

//////////////////////////////////////////////////////////////////////////////
// TC_2: 正常调用有内存分配的函数TC
//////////////////////////////////////////////////////////////////////////////
int memory_malloc2(char **pdata);

int test_memory_malloc2() {
    printf("\n////////////////////////////////\n");
    printf("%s\n", __func__);
    printf("////////////////////////////////\n\n");

    char *data;
    int   result = memory_malloc2(&data);
    if (result == 0)
        printf("%s\n", data);
    else
        printf("%s error\n", __func__);

    return 0;
}

/**
 * 函数说明：测试函数调用内存分配，传入指针方式
 */
int memory_malloc2(char **pdata) {
    *pdata = "aaa";
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
// TC_3: 正常调用有内存分配的函数TC2
//////////////////////////////////////////////////////////////////////////////
char *memory_malloc3();

int test_memory_malloc3() {
    printf("\n////////////////////////////////\n");
    printf("%s\n", __func__);
    printf("////////////////////////////////\n\n");

    char *data;
    data = memory_malloc3();
    if (data != NULL) {
        printf("%s\n", data);
        free(data);
    } else
        printf("%s error\n", __func__);

    return 0;
}
/**
 * 函数说明：测试函数调用内存分配，内部分配
 */
char *memory_malloc3() {
    char *x = malloc(10);
    x       = "bbb";
    return x;
}

//////////////////////////////////////////////////////////////////////////////
// TC_4: 未释放内存导致内存泄漏TC
// 函数说明：测试内存泄漏
// 测试方法：`make memcheck`
//////////////////////////////////////////////////////////////////////////////
void test_memory_leak() {
    printf("\n////////////////////////////////\n");
    printf("%s\n", __func__);
    printf("////////////////////////////////\n\n");

    char *x = malloc(10);
    x       = "ddd";
    printf("%s\n", x);
}

int aqnote_stdlib_malloc() {
    test_memory_malloc1();
    // test_memory_malloc2();
    // test_memory_malloc3();
    // test_memory_leak();

    getchar();
    return 0;
}
