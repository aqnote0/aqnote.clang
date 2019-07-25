/*
 * =====================================================================================
 *
 *       Filename:  test02.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/16/19 08:44:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
main() {
    int *p = NULL;
#undef NULL

    if(p == NULL)
        printf("NULL");
    else
        printf("Nill");
}

// OUTPUT:
// Compile error, as the macro is undefined NULL is considered as undeclared.
