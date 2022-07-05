
#include <stdio.h>
#include <stdlib.h>

// void apply(int a[], int numberOfElements, int sizeOfElement, void (*cmp)(int a[], int
//numberOfElements, int b[], int sizeOfElement), int b[]) {
//   cmp(a, numberOfElements, b, sizeOfElement);
// }

//--> modified

void apply(void *in, int numberOfElements, int sizeOfElement, void (*cmp)(void *in, void *out), void *out) {
  void *end = in + numberOfElements * sizeOfElement;
  while (in < end) {
    cmp(in, out);
    in += sizeOfElement;
    out += sizeOfElement;
  }
}
