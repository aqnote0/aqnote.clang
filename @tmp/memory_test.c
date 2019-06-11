
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char  name[64 + 1];
    char *desc;

    strcpy(name, "Hello world!");

    desc = malloc(30 * sizeof(char));
    if (desc == NULL) {
        fprintf(stderr, "ERROR: unable to malloc require memory\n");
        return -1;
    }

    strcpy(desc, "Hello world desc");
    printf("desc: %s\n", desc);

    desc = realloc(desc, 65 * sizeof(char));
    if (desc == NULL) {
        fprintf(stderr, "ERROR: unable to realloc require memory\n");
        return -2;
    }

    strcpy(desc, "Hello world desc2");
    printf("desc: %s\n", desc);
    free(desc);

    printf("name: %s\n", name);
    return 0;
}
