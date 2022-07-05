#include "Stackl.h"
#include <stdio.h>
#include <stdlib.h>

Stack *createStack() {
  Stack *res = malloc(sizeof(Stack));
  if (!res) return 0;
  *res = 0;
  return res;
}

//-------------------------------------------------------------------------
status push(Stack *s, int elements) {
  // Create a box for the Stack to be created (note this is temporary)
  Box *tmp = (Box *)malloc(sizeof(Box));
  if (!tmp) return ERRALLOC;
  // create a stack as the next element in the Box
  tmp->next = *s;
  tmp->val = elements;
  // make the initial pointer to refernce this newly added Stack
  *s = tmp;
  return OK;
}

//-------------------------------------------------------------------------
// stack varibale =*s
void destroyStack(Stack *s) {
  // remove the elements in the stack
  Stack tmp;
  // Box *temp; // or Stack temp;
  while (*s) {
    // the sole aim here is to gradually shot the pointer to the next element and destroy
    // the temp variable to free it up after each assignment

    // asigning the value at *s which a BOX of type below to tmp
    // changing the key which is the pointer *s to point to the next element
    // removing the tmp varible from memory. Rmember Stack tmp is a pointer
    // so we have to call free to remove it from memory

    // the aim
    tmp = *s;
    *s = tmp->next;
    free(tmp);
  }
  free(s);
}

//-------------------------------------------------------------------------
int isEmpty(Stack *s) {
  // chekc if the stack is empty
  // TODO: printf("Topmost Value Before Free:  %d\n", tmp->val);
  // Topmost Value Before Free:  9
  // free(tmp);
  // TODO: printf("Topmost Value After Free:  %d\n", tmp->val);
  // Topmost Value After Free:  -678657840
  // TODO: printf("Second Value:  %d\n", checker->val);
  // Second Value:  8
  return !*s;
}

//-------------------------------------------------------------------------
status pop(Stack *s) {
  // create a temporary variable to store topmost stack
  Stack tmp = *s;
  if (!tmp) return ERREMPTY;
  // assign the possiton of the topmost variable to the next stack member
  *s = tmp->next;
  // Stack checker = *s;
  /*Print the address pointed to by s*/
  // printf("Value:  %d\n", checker->val);
  // remove the pointer to the first varibale
  free(tmp);
  // printf("Value:  %p\n", s);
  return OK;
}

//-------------------------------------------------------------------------
status top(Stack *s, int *res) {
  // create a temporary variable
  if (!*s) return ERREMPTY;
  Stack tmp;
  if (!tmp) return ERREMPTY;
  // Assign the stack to the tmp
  tmp = *s;
  *res = tmp->val;
  // printf("%d\n", tmp->val);
  return OK;
  // NOTE: A pointer can exist in 2 forms:
  // 1) a value
  // 2) a key
  // a key i mostly used for reassigning the attributes of that pointer in memeory
  // a value is used like a nirmal variable.(*s) converts a key to a value which is important
  // in order to access -> values
  // return (*s)->val;
}