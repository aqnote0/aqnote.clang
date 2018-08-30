
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy(char *orgi);

int main() {
  char *hello;
  char *world;

  hello = copy("Hello");
  free(hello);
  world = copy("World");
  free(world);

  printf("hello: %s\nworld: %s\n", hello, world);
  return 0;
}

char *copy(char *orgi) {
  char *result = malloc(strlen(orgi)+1);
  if(!result) {
    fprintf(stderr, "copy:result:malloc error");
    return NULL;
  }
  strcpy(result, orgi);
  printf("copy func: result=%s\n", result);
  return result;
}
