#include <stdio.h>
#include <limits.h>
#include <time.h>
#include "com.aqnote.sort.h"

int main(int argc, char *argv[])
{

  if(argc != 2) {
    printf("Usage %s ch \n", argv[0]);
    return 0;
  }

  char ch = *(argv[1]);

	int array[] = {
    INT_MIN, 9, 0, 8, 7, 5, 6, 2, 3, 1, 4, INT_MAX
  };
  int elementSize = sizeof(array[0]);
  int arrayLength = sizeof(array) / elementSize;
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
