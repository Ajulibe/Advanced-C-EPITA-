#include "Stackl.h"
#include <stdio.h>
#include <stdlib.h>

Stack *createStack() {
  Stack *res = malloc(sizeof(Stack));
  if (!res) return 0;
  *res = 0;
  return res;
}

void destroyStack(Stack *s) {
  Stack tmp;
  while (*s) {
    tmp = *s;
    *s = tmp->next;
    free(tmp);
  }
  free(s);
}

static Box *available = 0;
// create a varibale tracker of type BOX

status push(Stack *s, void *elements) {
  // because the call to malloc is memory intensive,
  //out aim here is the minimize the call to malloc
  Box *tmp = (Box *)malloc(sizeof(Box));
  if (!tmp) return ERRALLOC;
  tmp->next = *s;
  tmp->val = elements;
  *s = tmp;
  return OK;
}

// status push(Stack *s, void *elements) {
//   //----New code -----------------
//   // because the call to malloc is memory intensive, out aim here is the minimize the call to malloc
//   // Box *tmp = (Box *)malloc(sizeof(Box));
//   Box *tmp = available;
//   // check tf the box is true. A box can only be true if
//   if (tmp) {
//     available = tmp->next;
//   } else {
//     tmp = (Box *)malloc(sizeof(Box));
//   }
// }

status pop(Stack *s) {
  Stack tmp = *s;
  if (!tmp) return ERREMPTY;
  *s = tmp->next;
  free(tmp);
  return OK;
}

//-------------------------------------------------------------------------
int isEmpty(Stack *s) {
  return !*s;
}

status top(Stack *s, void *res) {
  if (!*s) return ERREMPTY;
  Stack tmp;
  if (!tmp) return ERREMPTY;
  tmp = *s;
  // this works but how do we assign it to res
  // TODO: assign a void pinter to an interger in a generic function
  // printf("%d\n", *(int *)tmp->val);

  printf("before call\n");
  printf("%d\n", *(void **)tmp->val);
  printf("after call\n");
  // The first thinh to know is that in order to pass a void start by address, it must be
  // passed as void **. The only problem there is that void ** is not compatible with
  // all datatypes but they can be dereferenced.
  // We will cast the final result to a void ** because we want to derefercne
  *(void **)res = tmp->val;

  return OK;
}
