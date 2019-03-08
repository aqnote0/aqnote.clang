
#include <stdio.h>

#define MAX_NUM 8

int chessBoard[][] = malloc(MAX_NUM*MAX_NUM*sizeof(int));

int main()
{
  for(int i=0; i<MAX_NUM*MAX_NUM; i++)
    chessBoard[i/MAX_NUM][i%MAX_NUM] = 0;

  return 0;
}



