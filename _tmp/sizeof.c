/* example1.4: sizeof */
#include <stdio.h>

int main()
{
  printf("sizeof(char)=%ld\n", sizeof(char));
  printf("sizeof(unsigned char)=%ld\n", sizeof(unsigned char));
  printf("================\n");
  
  printf("sizeof(short)=%ld\n", sizeof(short));
  printf("sizeof(unsigned short)=%ld\n", sizeof(unsigned short));
  printf("sizeof(short int)=%ld\n", sizeof(short int));
  printf("sizeof(unsigned short int)=%ld\n", sizeof(unsigned short int));
  printf("================\n");

  printf("sizeof(int)=%ld\n", sizeof(int));
  printf("sizeof(unsigned int)=%ld\n", sizeof(unsigned int));
  printf("================\n");

  printf("sizeof(long)=%ld\n", sizeof(long));
  printf("sizeof(unsigned long)=%ld\n", sizeof(unsigned long));
  printf("sizeof(long int)=%ld\n", sizeof(long int));
  printf("sizeof(unsigned long int)=%ld\n", sizeof(unsigned long int));
  printf("================\n");

  printf("sizeof(float)=%ld\n", sizeof(float));
  printf("sizeof(double)=%ld\n", sizeof(double));
  getchar();

  return 0;
}
