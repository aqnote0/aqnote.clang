
#include <stdio.h>

int main() {
    /* 能执行成功，说明是-(a++)，右++是在本行语句执行结束后，再对变量做修改 */
    int a = 3;
    printf("-a++ = %d\n", -a++);  // -3
    printf("a = %d\n", a);        // 4

    a = 3;
    printf("-++a = %d\n", -++a);  // -4
    printf("a = %d\n", a);        // 4

    a = 3;
    printf("-a-- = %d\n", -a--);  // -3
    printf("a = %d\n", a);        // 2

    a = 3;
    printf("-(--a) = %d\n", -(--a));  // -2
    printf("a = %d\n", a);            // 2

    printf("---a = 报错：gcc编译器解析为--(-a)\n");
    printf("++(-a) = 报错：++ --不能用于表达式\n");
    /* 报错，gcc编译器解析为--(-a)
    a = 3;
    printf("%d\n", ---a);
    */

    /* 报错，编译器解析为++(-a)；++ --  不能用于表达式
    a = 3
    printf("%d\n", ++-a);
    */
    getchar();

    return 0;
}
