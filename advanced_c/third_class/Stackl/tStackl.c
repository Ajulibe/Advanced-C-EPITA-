#include "Stackl.h"
#include <stdio.h>

int main() {
  int SIZE = 10;
  int i;
  Stack *s = createStack();
  if (!s) {
    fprintf(stderr, "Error: createStack() failed\n");
    return 1;
  }
  for (i = 0; i < SIZE; i++) {
    push(s, i);
  }
  int result = isEmpty(s);
  printf("%d\n", result);
  top(s);
  pop(s);
  top(s);

  // while (!isEmpty(s)) {
  //   printf("%d\n", top(s));
  //   // pop(s);
  // }
  destroyStack(s);
  return 0;
}
