
#include <stdio.h>

int main() {

  int i = 0;
  while(i++ < 128)
  {
    if(i%8==0) 
      printf("\n");
    printf("%c ", i);
  }

  printf("\n");

  return 0;
}
