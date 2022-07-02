#include "status.h"

typedef struct Box {
  void *val;
  struct Box *next;
} Box, *Stack;

Stack *createStack();
status push(Stack *stack, void *elements);
status pop(Stack *stack);
status top(Stack *stack, void *elements);
int isEmpty(Stack *stack);
void destroyStack(Stack *stack);