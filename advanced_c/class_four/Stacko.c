#include "Stacko.h"

//to understand this you have to look at how it form in the structures of
Stack *createStack(int eltSize) {
  Stack *res = (Stack *)malloc(sizeof(Stack));

  if (!res) return 0;

  res->eltSize = eltSize;
  res-> head = 0
  return res;
  // at this creation state the tsack is empty
}

void destroyStack(Stack *s) {
  while (*s) {
    // assign the memomory addres of the
    // current stack to a temporary value

    Stack temp = *s;
    // assign the current pointer to the address of the next
    *s = temp->next;
    // detlete the temporary value
    free(temp);

    // this essentailly starts freeing up memory from behind
  }
}

void pop(Stack *s) {
  Stack temp = *s;
  // assign the current pointer to the address of the next
  *s = temp->next;
  // detlete the temporary value
  free(temp);
}

int top(Stack *s) {
  return *s->val;
}

void push(Stack *s, int element) {
  //if there is not *s
  //chekc the 
  Box *tmp = (Box *)malloc(sizeof(Box));
  if(!tmp) return ERRALLOC;
  /**Cannot do an if check*/
  tmp->next = *s;
  tmp->val = element;
  *s = tmp;
}