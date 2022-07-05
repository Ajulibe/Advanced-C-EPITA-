#include "Stacko.h"
#include <stdio.h>

int main() {
  Stack *s = createStack(sizeof(int));
  if (!s) {
    printf("createStack failed--starting\n");
    return 1;
  }
  int i1 = 2, i2 = 3;
  status st = push(s, &i1);
  if (st) {
    fprintf(stderr, "%s\n", message(st));
    return 2;
  }
  st = push(s, &i2);
  if (st) {
    fprintf(stderr, "%s\n", message(st));
    return 2;
  }
  while (!isEmpty(s)) {
    int e;
    if (st = top(s, &e)) {
      fprintf(stderr, "%s\n", message(st));
      return 3;
    }
    if (st = pop(s)) {
      fprintf(stderr, "%s\n", message(st));
      return 4;
    }
    printf("%d\n", e);
  }
  destroyStack(s);
  //--> Added this
  if (!s) {
    printf("createStack failed--ending\n");
    return 1;
  }
  return 0;
}
