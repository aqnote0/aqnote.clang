#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// linux
#include <unistd.h>


int main()
{

  int i=0;
  int *pa = malloc(1*sizeof(int));
  while(1)
  {
    unsigned long int size = (int)pow(2, i++)*sizeof(int);
    if (size < 0) size = ULONG_MAX;
    pa = realloc(pa, size);
    for(int j=0; j<size/sizeof(int);j++)
      pa[j] = j;
    printf("realloc(pa, %ld)\n", size);
    //usleep(1000);
    sleep(1);
  }

  return 0;
}



