/* Stack.h -- contiguous implementation of a stack of integers */

typedef struct {
  int top;
  int max;
  int* elts;
} Stack;

Stack* createStack(int maxSize);
void destroyStack(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int elt);
void pop(Stack* s);
int top(Stack* s);