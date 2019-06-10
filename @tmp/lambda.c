
#include <stdio.h>

#define LAMBDA(C_) ({ C_ _; })

void func(int nb, void (*f)(int)) {
    int i;
    for (i = 0; i < nb; i++)
        f(i);
}

void callback(int v) {
    printf("%d\n", v);
}

int main(void) {
    // for clang
    // void (^ydprint)(char *) = ^(char *str){
    //   printf("%s\n", str);
    // };
    //
    // ydprint("12345");

    // for gcc
    // case1
    // func(4, callback);

    // case2
    // void callback(int v) { printf("%d\n", v); }
    // func(4, callback);

    // case3
    // func(4, ({
    //      void callback(int v) {printf("%d\n", v);}
    //      callback;
    //      }));

    func(4, LAMBDA(void _(int v) { printf("%d\n", v); }));

    getchar();
    return 0;
}
