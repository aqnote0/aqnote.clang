
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

struct A {
    int   a;
    void *b;
};

typedef struct A A;

int main() {

    // case1
    struct A *a = malloc(sizeof(struct A));
    a->a        = 1;
    a->b        = "string";

    printf("%#x,%p,%d\n", &a, a, a->a);

    // case2
    time_t t;
    srand(time(&t));
    while (1) {
        int   value = rand();
        void *a     = &value;
        printf("%#x,%d\n", &a, (int *)a);
        usleep(1000);
    }

    return 0;
}
