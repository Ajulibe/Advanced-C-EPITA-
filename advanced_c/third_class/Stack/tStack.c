#include "Stack.h"
#include <stdio.h>

int main() {
  int SIZE = 10;
  int i;
  Stack *s = createStack(SIZE);
  if (!s) {
    fprintf(stderr, "Error: createStack() failed\n");
    return 1;
  }
  printf("%p", &s);
  for (i = 0; i < SIZE; i++) {
    push(s, i);
  }
  while (!isEmpty(s)) {
    printf("%d\n", top(s));
    pop(s);
  }
  destroyStack(s);
  return 0;
}
