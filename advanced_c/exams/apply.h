#ifndef __APPLY_H__
#define __APPLY_H__



void apply(void *in, int numberOfElements, int sizeOfElement, void (*cmp)(void *in, void *out), void *out);

#endif