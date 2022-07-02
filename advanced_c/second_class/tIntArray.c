/* tIntArray.c -- test for array functions */

#include "intArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int nWords, char *words[]) {
  int size = nWords - 1;
  int i;
  int *a;

  if (nWords > 1) {
    if (!strcmp(words[1], "-s")) {
      size = atoi(words[2]);
      a = createRandomArray(size);
      if (!a) {
        fprintf(stderr, "error creating array\n");
        return 1;
      }
    } else {
      a = createArray(size);
      if (!a) {
        fprintf(stderr, "error creating array\n");
        return 1;
      }
      for (i = 0; i < nWords - 1; i++)
        a[i] = atoi(words[i + 1]);
    }
  }
  displayArray(a, size);

  sortArray(a, size);
  displayArray(a, size);
  destroyArray(&a, size);
  if (a != 0) {
    fprintf(stderr, "error destroying array\n");
    return 2;
  }

  return 0;
}

/// ./tIntArray 4 8 3 2 5
// ./tIntArray -s 20