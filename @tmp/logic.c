
#include <stdio.h>

int main()
{
  // int n,m=3; <==> int m=3,n; <==> int n; int m=3;
  int n=3,m;
  m = 2 && n++;
  printf("%d %d\n", n, m); // 4 2

  return 0;
}
