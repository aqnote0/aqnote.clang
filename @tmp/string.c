
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char *str1 = "First";
    char *str2 = "Second";

    str1 = malloc(strlen(str2) + 1);
    if (str1 == NULL) {
        printf("malloc str1 error.\n");
        return -1;
    }
    strcpy(str1, str2);
    printf("str1 = %s\n", str1);
    getchar();
    printf("str2 = %s\n", str2);

    free(str1);
    getchar();
    return 0;
}
