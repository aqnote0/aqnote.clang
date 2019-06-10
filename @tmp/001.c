#include <stdio.h>

int main() {
    int total = 1;
    int i     = 1;

    while (i <= 11) {
        total *= i;
        i += 2;
    }

    printf("total=%d\n", total);

    getchar();

    return 0;
}
