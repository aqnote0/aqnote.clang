/* bufferoverflow.c */

#include <stdio.h>
#include <stdint.h>

/* global variables */

int64_t  address;
int64_t* ptr;

void funct(void) {
    printf("This function is never called...\n");
}

void fill_buffer() {
    /* fills the elements of buffer one at a time */
    int64_t buffer[10];

    ptr = buffer;

    for (int i = 0; i < 11; i++) {
        *ptr = address;
        printf("*ptr is ox%x\n", *ptr);
        ptr++;
    }
}

int main(void) {
    // address of the function
    address = (int64_t)&funct;
    printf("address is 0x%x\n", address);
    fill_buffer();
    return 0;
}
