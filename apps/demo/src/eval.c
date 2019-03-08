
#include <stdio.h>

int main()
{
  int a;

  a = 3; a += 4;
  printf("%d\n", a); // 7

  a = 3; a -= 4;
  printf("%d\n", a); // -1

  a = 3; a *= 4;
  printf("%d\n", a); // 12

  a = 3; a /= 4;
  printf("%d\n", 0); // 0

  a = 3; a %= 4;
  printf("%d\n", 3); // 3

  a = 3; a <<= 4;
  printf("%d\n", a); // 48

  a = 3; a >>= 4;
  printf("%d\n", a); // 0

  a = 3; a &= 4;
  printf("%d\n", a); // 0

  a = 3; a |= 4;
  printf("%d\n", a); // 7

  a = 3; a ^= 4;
  printf("%d\n", a); // 7

  int b, c;

  a=b=c=3;
  printf("%d %d %d\n", a, b, c); // 3 3 3

  a=(b=3);
  printf("%d %d\n", a, b); // 3 3

  a=3+(b=4);
  printf("%d %d\n", a, b); // 3 7

  a=(b=3)+(c=4);
  printf("%d %d %d\n", a, b, c); // 7 3 4

  a=(b=3)/(c=4);
  printf("%d %d %d\n", a, b, c); // 0 3 4

  b=(a=3*4,a*5);
  printf("%d %d\n", a, b); // 12 60

  b=(a=3*4,a*5, a+6);
  printf("%d %d\n", a, b); // 12 18

  b=a=3,a*3;
  printf("%d %d\n", a, b); // 3 3
    

  return 0;
}
