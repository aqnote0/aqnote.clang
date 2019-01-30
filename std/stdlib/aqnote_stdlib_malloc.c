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

/**
 * 函数说明：测试内存分配，传入方式
 * 
*/
int test_memory_malloc1(char **idata)
{
    *idata = "aaa";
    return 0;
}

/**
 * 函数说明：测试内存分配，内部分配
 * 
*/
char *test_memory_malloc2()
{
    char *x = malloc(10);
    x = "bbb";
    return x;
}

/**
 * 函数说明：测试内存分配
 * 
*/
void test_memory_malloc3()
{
    char *x = malloc(10);
    x = "ccc";
    printf("%s\n", x);
    free(x);
}

/**
 * 函数说明：测试内存泄漏
 * 测试方法：`make memcheck`
 * 
*/
void test_memory_leak()
{
    char *x = malloc(10);
    x = "ddd";
    printf("%s\n", x);
}

int aqnote_stdlib_malloc()
{
    printf("start running test case\n");

    char *data;
    int result = test_memory_malloc1(&data);
    if (result == 0)
        printf("%s\n", data);
    else
        printf("test_memory_malloc1 error\n");

    //////////////////////////////////////////////////////////////////////////
    data = test_memory_malloc2();
    if (data != NULL)
    {
        printf("%s\n", data);
        free(data);
    }
    else
        printf("test_memory_malloc1 error\n");

    //////////////////////////////////////////////////////////////////////////
    test_memory_malloc3();

    test_memory_leak();

    printf("end running test case\n");

    getchar();
    return 0;
}
