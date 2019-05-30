
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline(char *, int *);
char *reallocmem(char *, int);

int main() {

  char *p = NULL;
  int max = 10;
  p = malloc(max);
  if(!p) {
    fprintf(stderr, "main:p:malloc error");
    return -1;
  }
  *p = '\0';

  p = readline(p, &max);
  printf("p: %s\n", p);
  free(p);

  return 0;
}

char *readline(char *p, int *maxlen) {

  char c;
  int count = strlen(p);
  while((c=getchar()) != EOF) {
    if(count == (*maxlen - 1)) {
      *(p + (*maxlen - 1)) = '\0';
      *maxlen = *maxlen * 2;
      p = reallocmem(p, *maxlen);
      if(!p) {
        fprintf(stderr, "readline:p:allocmem error");
        return NULL;
      }
    }
    count += 1;
    strncat(p, &c, 1);
  }
  return p;
}

static int realloctimes = 0;
char *reallocmem(char *p, int maxlen) {
  char *q = NULL;
  q = realloc(p, maxlen);
  if(!q) {
    fprintf(stderr, "allocmem:q:realloc error");
    return NULL;
  }

  if(realloctimes == 0) {
    printf("\nreallocmem:%d\n", ++realloctimes);
  } else {
    printf("reallocmem:%d\n", ++realloctimes);
  }
  return q;
}

