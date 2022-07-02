
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Creation of and array of intergers that must be zeroed after creation
//  return a pointer to an array of size
int *createArray(int size) {
  int *my_array = (int *)malloc(size * sizeof(int));
  int i;
  // check if the memory is allocated
  if (!my_array) return 0; // return 0 if the memory is not allocated
  // Zeroring the Array
  for (i = 0; i < size; i++)
    my_array[i] = 0;
  return my_array;
}

void printArray(int *array, int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);
}

int main(void) {
  int size;
  int *res;
  res = createArray(size);
  printArray(res, 10);
}
