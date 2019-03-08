
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
  int num;
  printf("input num>");
  scanf("%d", &num);
  assert(num > 0);
  printf("input num is: %d\n", num);

  char str[10];
  printf("input string>");
  scanf("%s", str);
  assert(str != NULL);
  printf("input str is: %s\n", str);

  getchar();
  return 0;
}
