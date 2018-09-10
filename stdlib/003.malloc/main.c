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
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // ## Finding Memory Leaks With Valgrind
    char *x = malloc(10); /* or, in C++, "char *x = new char[10] */

    // ## Finding Invalid Pointer Use With Valgrind
    x[10] = 'a';

    // ## Detecting The Use Of Uninitialized Variables
    int y;
    if(y == 0)
    {
        printf("X is zero"); /* replace with cout and include 
                                iostream for C++ */
    }
    return 0;
}