
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linux
#include <unistd.h>

typedef struct _A A;
struct _A
{
  int a;
  void *b;
};


int main()
{

  // case1
  A *a = malloc(sizeof(A));
  a->a = 1;
  a->b="string";

  printf("%#x,%p,%d\n", &a, a, a->a);


  // case2
  time_t t;
  srand(time(&t));
  while(1)
  {
    int value = rand();
    void *a = &value;
    printf("%#x,%d\n", &a, (int *)a);
    usleep(1000);
  }


 
  return 0;
}
