

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Stack *res = createStack(4);
  printf("%d", res->top);
}