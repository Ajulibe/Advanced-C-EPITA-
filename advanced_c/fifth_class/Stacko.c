#include "Stacko.h"
#include <stdlib.h>

Stack *createStack(int eltSize) {
  Stack *res = (Stack *)malloc(sizeof(Stack));
  if (!res) return 0;
  res->eltSize = eltSize;
  res->head = 0;
  return res;
  // at this creation state the stack is empty
}

status push(Stack *s, void *element) {
  // Box *newBox = (Box *)malloc(sizeof(Box) + s->eltSize - 1);
  // newBox->val[1] = element;

  // if (s->head == 0) {
  //   newBox->next = 0;
  //   s->head = newBox;
  // } else {
  //   Box *oldBox = (Box *)malloc(sizeof(Box));
  //   if (!oldBox) return ERRALLOC;
  //   oldBox = s->head;
  //   newBox->next = oldBox;
  //   s->head = newBox;
  // }

  //* MORE ELEGANT FROM THE PROF
  // look at the bof definition. it is made up of a BOX and and ELEMENT of 1 Byte
  // therefore we will create same as shown below
  Box *temp = (Box *)malloc(sizeof(Box) + s->eltSize - 1);
  if (!temp)
    return ERRALLOC;
  temp->next = s->head;
  s->head = temp;
  // note, you can be tempted to use temp->val = element BUT remember,
  // that only works for pointers which this is not.
  //  to copy byte, you must use memcpy
  memcpy(temp->val, element, s->eltSize);
  return OK;
}

void destroyStack(Stack *s) {
  Box *temp;
  temp = s->head;
  while (temp) {
    s->head = temp->next;
    free(temp);
  }
  free(s);
}

int isEmpty(Stack *s) {
  return s->head == 0;
}

status pop(Stack *s) {
  Box *temp = s->head;
  s->head = temp->next;
  free(temp);
}

status top(Stack *s, void *res) {
  if (!s->head)
    return ERREMPTY;
  memcpy(res, s->head->val, s->eltSize);
  return OK;
}
