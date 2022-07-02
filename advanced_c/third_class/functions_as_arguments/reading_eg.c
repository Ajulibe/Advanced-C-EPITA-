#include <stdio.h>

// the formal definition of a function as an argument in C is:
// void myFunction(void (*f)(int));
// TODO: the function in the ARGUMENT is: void (*f)(int)

void printNumber(int nbr) {
  printf("%d\n", nbr);
}
void myFunction(void (*f)(int)) {
  for (int i = 0; i < 5; i++) {
    (*f)(i);
  }
}

void print() {
  printf("Hello World!");
}
void helloworld(void (*f)()) {
  f();
}

// main function
int main(void) {
  helloworld(print);
  myFunction(printNumber);
  return (0);
}
