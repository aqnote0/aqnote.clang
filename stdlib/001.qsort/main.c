
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * function: test qsort function
 * author: Peng Li<aqnote@aqnote.com>
 * date: 20180130
 *
*/

int comparator(const void *, const void *);

int main() 
{
  int array[] = {INT_MIN, 1, 3, 2, INT_MAX, 4, 0, 8, 7, 9, 5, 6};

  int elementSize = sizeof(int);
  int length = sizeof(array)/elementSize;

  printf("array_length=%d element_size=%d \n", length, elementSize);
  qsort(array, length, elementSize, comparator);

  for(int i=0; i<length; i++) 
  {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}

/**
 * <0 The element pointed by pa goes before the element pointed by pb 
 * =0 The element pointed by pa is equivalent to the element pointed by pb
 * >0 The element pointed by pa goes after the element pointed by pb
 */
int comparator(const void *pa, const void *pb) 
{
  int a = *(const int*)pa;
  int b = *(const int*)pb;

  if(a > b) return 1;
  else if(a < b) return -1;
  else return 0;
}
