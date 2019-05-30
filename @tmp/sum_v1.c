/* example1.2: Calculate the sum of a and b */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <locale.h>

int add(int, int);

/* This is the main program */
int main(int argc, char* argv[]) 
{
  if(argc <=2)
  {
    printf("Usage: %s number1 number2\n", argv[0]);
    return 1;
  }

  setlocale(LC_ALL, "en_US.utf8");

  int a, b, sum;
  a = atoi(argv[1]);
  b= atoi(argv[2]); 

//  scanf("%d%d", &a, &b);
  printf("a=%d, b=%d\n", a, b);
  sum = add(a, b);
  printf("sum=%d\n", sum);
  getchar();

  return 0;
}

/* This function calculates the sum of x and y */
int add(int x, int y)
{
  return x + y;
}
