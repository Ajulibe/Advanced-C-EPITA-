
#include "apply.h"
#include <stdio.h>
#include <stdlib.h>

void functionToCall(void *in, void *out) {
  int i;
  int *tmp[6];
  for (i=0; i<6; i++){
   tmp[i] = ((int *)in)[i] * 3;
  }
*(int*)out = *tmp;

//->Profs version
//but here he assumes that this function is called on each value of the array
//me i assume the whole array is passed mutated and sent out
// *(int*)out = 3 * *(int*)in;
}

int main() {
  int i, j;
  int numberOfElements = 6;
  int b[numberOfElements];
  int a[] = {1, 4, 2, 8, 5, 7};
  int sizeOfElement = 4;

  //NOTE: to find the number of elements in the array
  //sizeof(a) / sizeof(int)

  apply(a, numberOfElements, sizeOfElement, functionToCall, b);
  for( i=0; i<numberOfElements; i++){
    printf("%d\n", b[i]);
  }
}

//--- Expo function copied off Stack overflow

// #include <string.h>
// #include <stdlib.h>
// void p(int *a){
//    int *b = (int*)malloc(sizeof(int)*4);
//    memcpy(b, a, sizeof(int)*4);

//     //make changes to b.
//    b[0] = 6;
//    b[1] = 7;
//    b[2] = 8;
//    b[3] = 9;
// }

// int main(int argc, char **argv)
// {
//     int *a = (int*)malloc(sizeof(int)*4);

//     // add values to a
//     a[0] = 1;
//     a[1] = 2;
//     a[2] = 3;
//     a[3] = 4;

//     p(a);

// return 0;
// }
