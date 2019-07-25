
#include <stdio.h>
#include <string.h>

int main() {
    char* uch = "\u00B7";
    printf("uch=%s\n", uch);
    printf("\u00b7\n");
    printf("\xb7\n");
    getchar();

    return 0;
}
