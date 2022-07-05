#include "Stacko.h"
#include <String.h>
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
  // temp creates a neutral ground where values can be stored
  // s->head = s->head->next
  //  the head now points to th next box
  // in an optimixation case, we do this as hsown innnote
  // temp->next = available;
  //* Preserving the available box in the next region
  // available = temp
  // temp->next = s->available;
  // s->available = temp;

  s->head = temp->next;

  free(temp);
}

status top(Stack *s, void *res) {
  if (!s->head)
    return ERREMPTY;
  memcpy(res, s->head->val, s->eltSize);
  return OK;
}
