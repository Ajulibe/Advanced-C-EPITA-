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

status push(Stack *s, void *elements) {
  Box *tmp = (Box *)malloc(sizeof(Box));
  if (!tmp) return ERRALLOC;
  tmp->next = *s;
  tmp->val = elements;
  *s = tmp;
  return OK;
}

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
  // the trick here is that void pointers always need to be casted back because
  // 1) they cannot be derefernced like before to return a value
  // eg:
  // FIXME: copied from https://www.geeksforgeeks.org/void-pointer-c-cpp/
  // int a = 10;
  // void *ptr = &a;
  // printf("%d", *ptr);
  // will not run

  //---------------------------------------------------------------
  // THE CORRECTION BELOW WILL RUN CAUSE ITS BEEN TYPECASTED

  // int a = 10;
  // void *ptr = &a;
  // printf("%d", *(int *)ptr);

  // *res = tmp->val;
  // the code above now becomes recomes which is a pointer to a pointer
  // remeber the aim here is to give the *res key a new value. We already have the top value
  // this is (tmp->val) but we want to pass that value outside the function to the result
  // NOTE: during the push operation, temp->value is a void pointer
  // the below staement is saying res is a pointer that is pointing to another pointer tmp->val
  // from there we are getting the address and setting it to out tmp->val
  // TODO: remeber with malloc we always cast back to a (int*) because we are sure that
  // thats what is going to be stored there. here we are sure that what will be here is
  // a pointer to a pointer of type void. so we cast it and then derefernce
  // it to store its value. the main thing here is casting to indicate type.

  *(void **)res = tmp->val;

  return OK;
}
