/* bufferoverflow.c */

#include <stdio.h>

/* global variables */

int count, address;
int * ptr;

void funct(void) {
  printf("This function is never called...\n");
}

void fill_buffer() {
  /* fills the elements of buffer one at a time */
  int buffer[10];

  ptr = buffer;
    for(count = 0; count < 12; count++) {
      *ptr = address;
      printf("*ptr is %c\n", *ptr);
      ptr++;
   }
}

int main(void) {
  address = (int) &funct;  /* address of the function */
  printf("address is %d\n", address);
  fill_buffer();
  return 0;
}
