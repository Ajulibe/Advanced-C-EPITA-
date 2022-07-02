#include "Stack.h"
#include <stdio.h>

int main() {
  int i;
  Stack *s = createStack(100);
  if (!s) {
    fprintf(stderr, "Error: createStack() failed\n");
    return 1;
  }
  for (i = 0; i < 10; i++) {
    push(s, i);
  }
  while (!isEmpty(s)) {
    printf("%d\n", top(s));
    pop(s);
  }
  destroyStack(s);
  return 0;
}
