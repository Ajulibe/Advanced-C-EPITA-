/* Stack.h -- analogious implementation of a linked stack of integers */

typedef struct Box {
  int val;
  struct Box *next;
} Box, *Stack;

//--> below is the basica definition of a struct from wikipedia
/*
typedef struct tag_name {
   type member1;
   type member2;
} struct_alias;
*/

Stack *createStack();
void destroyStack(Stack *stack);
void push(Stack *stack, int elt);
int isEmpty(Stack *stack);
void pop(Stack *stack);
int top(Stack *stack);