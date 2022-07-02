/* Stack.h -- analogious implementation of a linked stack of integers */

typedef struct Box {
  int val;
  struct Box *next;
} Box, *Stack;


Stack *createStack();
void destroyStack(Stack *stack);
void push(Stack *stack, int elt);
int isEmpty(Stack *stack);
void pop(Stack *stack);
int top(Stack *stack);
