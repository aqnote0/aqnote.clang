/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/13/19 10:01:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

#include "moduleA.hpp"
#include "moduleB.hpp"

int main(int argc, char** argv)
{
    A a;
    cout << a.get() << endl;

    B b("Hello B");
    cout << b.get() << endl;
    return 0;
}

