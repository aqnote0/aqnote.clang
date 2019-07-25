#include <stdio.h>

int main(int argc, char **argv) {
    int i, a, b, tmp;
    printf("%3s %3s %3s\n", "A", "B", "AND");
    for (i = 0; i < 4; i++) {
        tmp = i;
        a   = tmp % 2;
        tmp /= 2;
        b = tmp % 2;
        printf("%3d %3d %3d\n", a, b, (a & b));
    }
    printf("----------------\n");
    printf("%3s %3s %3s\n", "A", "B", "OR");
    ;
    for (i = 0; i < 4; i++) {
        tmp = i;
        a   = tmp % 2;
        tmp /= 2;
        b = tmp % 2;
        printf("%3d %3d %3d\n", a, b, (a | b));
    }
    printf("----------------\n");
    printf("%3s %3s %3s\n", "A", "B", "XOR");
    for (i = 0; i < 4; i++) {
        tmp = i;
        a   = tmp % 2;
        tmp /= 2;
        b = tmp % 2;
        printf("%3d %3d %3d\n", a, b, (a ^ b));
    }

    return 0;
}