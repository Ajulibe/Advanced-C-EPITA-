// The aim here is to make the sort function truly generic
// This means that
//-------------------------------------------------------------------------------
// 1)- we should be able to sort not just an array of int, but also other DTypes
// like Float
//-------------------------------------------------------------------------------
// 2)- Should be able to take in a funciton as an argument to determine (DESC || ASC)

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

// FORMAT
// void myFunction(void (*f)(int));
// TODO: the function in the ARGUMENT is: void (*f)(int)
//_---------------------------------------------------_

/*new generic sort*/
// array = 2 | 3 | 4 | 5 | 6 | 7 | 8
// for l -> 2 | 3 | 4 | 5 | 6 | 7
// for r ->  3 | 4 | 5 | 6 | 7 | 8
void nSortArray(void *a, int size, int eltSize, int (*comp)(void *, void *)) {
  int l, r;
  // size if the no. of element in the array.
  // eltSize is added to function to determine the size of the memory created
  // NOTE: because we are using void, we cannot increment the values of each element
  // but rather their byte memory(i.e int -> 4 bytes)
  void *tmp = malloc(eltSize);
  for (l = 0; l < (size - 1) * eltSize; l += eltSize) {
    // means the l is increased not by 1 byte, but by 4(for int) which pushe
    // it to the next element in the memory.
    // traditionally when int is specified, it is pushed by one int which in 4bytes
    for (r = l + eltSize; r < (size)*eltSize; r += eltSize) {
      if (comp(a + l, a + r) > 0) {
        memcpy(tmp, a + l, eltSize);
        memcpy(tmp, a + r, eltSize);
        memcpy(a + r, tmp, eltSize);
      }
    }

    free(tmp);
  }