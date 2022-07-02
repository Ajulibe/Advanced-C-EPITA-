#include "Stackl.h"
#include <stdio.h>

int main() {
  int SIZE = 10;
  int i;
  int topelement;
  status st;

  Stack *s = createStack();
  if (!s) {
    fprintf(stderr, "Error: createStack() failed\n");
    return 1;
  }

  //-------------------------------------------------------
  for (i = 0; i < SIZE; i++) {
    st = push(s, i);
    // error checking
    if (st)
      print("%s\n", message(st));
  }
  int result = isEmpty(s);
  printf("%d\n", result);

  //-------------------------------------------------------
  st = top(s, &topelement);
  // error checking
  if (st) {
    exit(st);
  }

  //-------------------------------------------------------
  st = pop(s);
  // error checking
  if (st) {
    exit(st);
  }

  //-------------------------------------------------------
  st = top(s, &topelement);
  // error checking
  if (st) {
    exit(st);
  }

  // while (!isEmpty(s)) {
  //   printf("%d\n", top(s));
  //   // pop(s);
  // }
  destroyStack(s);
  return 0;
}
