/* Stack.h -- contiguous implementation of a stack of integers */

typedef struct Stack {
  int *elts;
  int max;
  int top;
} Stack;

Stack *createStack(int maxSize);
void destroyStack(Stack *stack);
void push(Stack *stack, int elt);
int isEmpty(Stack *stack);
void pop(Stack *stack);
int top(Stack *stack);
