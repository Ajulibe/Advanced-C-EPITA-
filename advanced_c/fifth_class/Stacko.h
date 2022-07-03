#ifndef __STACKO_H__
#define __STACKO_H__
#include "status.h"

typedef struct Box {
  struct Box *next;
  char val[1];
} Box;

typedef struct {
  Box *head;
  int eltSize;
} Stack;

Stack *createStack();
void destroyStack(Stack *stack);
status push(Stack *stack, void *elt);
int isEmpty(Stack *stack);
status pop(Stack *stack);
status top(Stack *stack, void *res);

#endif