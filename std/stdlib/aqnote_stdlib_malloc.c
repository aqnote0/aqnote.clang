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

//////////////////////////////////////////////////////////////////////////////
// TC_1: 正常内存分配TC
//////////////////////////////////////////////////////////////////////////////
void test_memory_malloc1()
{
    char *x = malloc(10);
    x = "ccc";
    printf("%s\n", x);
    free(x);
}

//////////////////////////////////////////////////////////////////////////////
// TC_2: 正常调用有内存分配的函数TC
//////////////////////////////////////////////////////////////////////////////
int memory_malloc2(char **pdata);

int test_memory_malloc2()
{
    char *data;
    int result = test_memory_malloc1_1(&data);
    if (result == 0)
        printf("%s\n", data);
    else
        printf("test_memory_malloc1 error\n");
}

/**
 * 函数说明：测试函数调用内存分配，传入指针方式
*/
int memory_malloc2(char **pdata)
{
    *pdata = "aaa";
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
// TC_3: 正常调用有内存分配的函数TC2
//////////////////////////////////////////////////////////////////////////////
char *memory_malloc3();

int test_memory_malloc3()
{
    char *data;
    data = test_memory_malloc2();
    if (data != NULL)
    {
        printf("%s\n", data);
        free(data);
    }
    else
        printf("test_memory_malloc2 error\n");
}
/**
 * 函数说明：测试函数调用内存分配，内部分配
*/
char *memory_malloc3()
{
    char *x = malloc(10);
    x = "bbb";
    return x;
}

//////////////////////////////////////////////////////////////////////////////
// TC_4: 未释放内存导致内存泄漏TC
// 函数说明：测试内存泄漏
// 测试方法：`make memcheck`
//////////////////////////////////////////////////////////////////////////////
void test_memory_leak()
{
    char *x = malloc(10);
    x = "ddd";
    printf("%s\n", x);
}

int aqnote_stdlib_malloc()
{
    printf("start running test case\n");

    test_memory_malloc1();
    test_memory_malloc2();
    test_memory_malloc3();
    test_memory_leak();

    printf("end running test case\n");
    getchar();
    return 0;
}
