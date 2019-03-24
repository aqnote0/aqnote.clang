#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "com.aqnote.sort.h"


/*
 * function: test qsort function
 * author: Peng Li<aqnote@aqnote.com>
 * date: 20180130
*/
int comparator(const void *, const void *);

int main(int argc, char **argv)
{

  if(argc != 2) {
    printf("Usage %s sortMethod: \"~[b|i|s|q]\" \n", argv[0]);
    return 0;
  }

  char ch = argv[1][0];

	int array[] = {
    INT_MAX, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, INT_MIN
  };
  int elementSize = sizeof(array[0]);
  int arrayLength = sizeof(array) / elementSize;
  printf("array_length=%d element_size=%d \n", arrayLength, elementSize);

  clock_t begin = clock();
  switch(ch) 
  {
    case 'b':
	    bubbleSort(array, arrayLength);
      break;
    case 'i':
	    insertSort(array, arrayLength);
      break;
    case 's':
      selectSort(array, arrayLength);
      break;
    case 'q':
      quickSort(array, arrayLength);
      break;
    default:
      qsort(array, arrayLength, elementSize, comparator);
      break;
  };
  clock_t end = clock();
  double between = 1000000.0*(end - begin)/CLOCKS_PER_SEC;
  printf("sort() cost time: %.2f\n", between);
	for (int i=0; i<arrayLength; i++) {
		printf("%d ", array[i]);
	}


	puts("\n");
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