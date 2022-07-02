#include "Stack.h"
#include <stdlib.h>

Stack *createStack(int maxSize) {
  Stack *res = malloc(sizeof(Stack));
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
void destroyStack(Stack *s) {
  // remove the elements in the stack
  free(s->elts);
  // destry the stack
  free(s);
}

//-------------------------------------------------------------------------
int isEmpty(Stack *s) {
  // chekc if the stack is empty
  return s->top == -1;
}

//-------------------------------------------------------------------------
void push(Stack *s, int elements) {
  // Store the elment in the next availbel position
  s->elts[s->top + 1] = elements;

  // change the top
  s->top++;
}

//-------------------------------------------------------------------------
void pop(Stack *s) {
  s->top--;
}

//-------------------------------------------------------------------------
int top(Stack *s) {
  return s->elts[s->top];
}