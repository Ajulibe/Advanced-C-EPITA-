/* intArray.c - array functions implementation */

#include "intArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size) {
  int *res;
  int i;
  res = (int *)malloc(size * sizeof(int));
  if (!res) return 0;
  for (i = 0; i < size; i++)
    res[i] = 0;
  return res;
}

/* display array as: "[ e1 e2 ... eN ]" */
void displayArray(int *a, int size) {
  int i;
  printf("[ ");
  for (i = 0; i < size; i++)
    printf("%d ", a[i]);
  puts("]");
}

/* "naive" sort of the array */
void sortArray(int *a, int size) {
  int l, r;
  for (l = 0; l < size - 1; l++)
    for (r = l + 1; r < size; r++)
      if (a[l] > a[r]) {
        int tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
      }
}

/* non-working version of destroyArray:
void destroyArray(int* ar, int size) {
  int i;
  for (i=0; i<size; i++) ar[i] = 0;
  free(ar);
  ar = 0;
}
*/
void destroyArray(int **ar, int size) {
  int i;
  for (i = 0; i < size; i++)
    (*ar)[i] = 0;
  free(*ar);
  (*ar) = 0;
}

int *createRandomArray(int size) {
  int *res;
  int i;
  res = (int *)malloc(size * sizeof(int));
  if (!res) return 0;
  srandom(time(0));
  for (i = 0; i < size; i++)
    res[i] = random() % (2 * size);
  return res;
}
