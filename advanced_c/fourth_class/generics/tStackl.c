#include "Stackl.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int SIZE = 10;
  void *i;
  void *topelement;
  status st;

  //------------------------------------------
  // create a stack and 2 intergers i1, i2
  int i1 = 2;
  int i2 = 3;

  Stack *s = createStack();
  if (!s) {
    return 1;
  }

  // for i1
  if (st = push(s, &i1)) {
    // printf(errorMessage(st));
    return st;
  }

  // for i2
  if (st = push(s, &i2)) {
    // printf(errorMessage(st));
    return st;
  }

  int result = isEmpty(s);
  printf("%d\n", result);

  //-------------------------------------------------------
  // refactor to satisfy class requirements
  int *e;
  st = top(s, &e);
  printf('%d\n', *e);
  // while (!isEmpty(s)) {
  //   printf("enter here");
  //   int *e;

  //   st = top(s, &e);
  //   if (st) {
  //     printf("about to print value");
  //     printf('%d', *e);
  //     st = pop(s);
  //     if (st) {
  //       printf("POP SUCCESFFUL");
  //     }
  //   }
  // }

  // destroyStack(s);
  return 0;
}
