/* intArray.h -- function profiles for arrays of integers */

/* create and zero an array of integers of a given size. Return the base address of the created array, or 0 in case of a failure */
int *createArray(int size);

/* create a random array of a given size, with random elements between 0 and
   2 * size */
int *createRandomArray(int size);

/* display array as: "[ e1 e2 ... eN ]" */
void displayArray(int *a, int size);

/* "naive" sort of the array */
void sortArray(int *a, int size);

/* set elements back to 0, frees memory allocated in createArray, and finally
 set base address to 0 */
void destroyArray(int **a, int size);