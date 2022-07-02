/*This is a stack with a linked representation*/
#include "status.h"

typedef struct Box {
  int val;
  struct Box *next;
} Box, *Stack;

Stack *createStack(); // returns a pointer so its good
void destroyStack(Stack *s);
void pop(Stack *s);
int top(Stack *s);
void push(Stack *s, int element);

/*
1). The first step is to look at what the functions return
2) then check if the functions can actually fail.

**/
