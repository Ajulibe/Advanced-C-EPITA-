/* Stackl.h -- analogious implementation of a linked stack of integers */
#include "Status.h"

typedef struct Box {
  int val;
  struct Box *next;
} Box, *Stack;

// always ask if the operation can fail. --> the minimum
// condition is that a stack will always be present so thats not a problem
// if it can then it must be transformed to a status
Stack *createStack();
status push(Stack *stack, int elt);
status pop(Stack *stack);
// refactored based on the general error handling rule
// i = top(s)  --> st top(s, &i)
status top(Stack *stack, int *res);
int isEmpty(Stack *stack);
void destroyStack(Stack *stack);
