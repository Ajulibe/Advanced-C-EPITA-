#include "Queue.h"
#include <stdlib.h>

Queue *createQueue(int maxSize) {
  Queue *res = malloc(sizeof(Queue));
  // each time we use malloc to create something we must use free to undo it

  if (!res) return 0;

  res->top = -1;
  res->max = maxSize;
  res->elts = (int *)malloc(maxSize * sizeof(int));

  // each time we use malloc to create something we must use free to undo it
  if (!res->elts) {
    free(res);
    return 0;
  }

  return res;
}

//-------------------------------------------------------------------------
void push(Queue *q, int elements) {
  // add the end of the elmts array
  q->elts[q->top + 1] = elements;
  // change the top
  q->top++;
}

//-------------------------------------------------------------------------
void destroyQueue(Queue *q) {
  // remove the elements in the stack
  free(q->elts);
  // destry the stack
  free(q);
}

//-------------------------------------------------------------------------
int isEmpty(Queue *q) {
  // chekc if the stack is empty
  return q->top == -1;
}

//------------------------------
int isFull(Queue *q) {
  return q->top + 1 == q->max;
}

//-------------------------------------------------------------------------
int top(Queue *q) {
  return q->elts[0];
}