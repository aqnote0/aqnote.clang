#include <stdio.h>


int main() 
{
  printf("leap year list:\n");
  int i = 2000;
  while(i <= 2500)
  {
    if((i%4==0 && i%100!=0) || (i%100 == 0 && i%400 !=0))
    {
       printf("%d\n", i); 
    }
    i++;  
  }

  return 0;
}
