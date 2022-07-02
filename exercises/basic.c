#include <stdio.h>

// 1. Write a C program to print your name, date of birth. and mobile number. Go to the editor
//  Expected Output:
//  Name   : Alexandra Abramov
//  DOB    : July 14, 1975
//  Mobile : 99-9999999999

// void printName() {
//   char name[] = "Alexandra Abramov";
//   char DOB[] = "July 14, 1975";
//   char mobile[] = "99 - 9999999999";
//   printf("Name   :  %s\n", name);
//   printf("DOB    :  %s\n", DOB);
//   printf("Mobile :  %s\n", mobile);
// }

// 5. Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches. Go to the editor
// Expected Output:
// Perimeter of the rectangle = 24 inches
// Area of the rectangle = 35 square inches

int computeArea(int a, int b) {
  int res;
  res = a * b;
  return res;
}

void changeValue(int *p) {
  *p = 5;
}

void createArray() {
  int A[] = {1, 2, 3, 4, 5};
  int = () malloc(sizeof(A))
}
int main() {
  int a = 200;
  changeValue(&a);
  printf("%d\n", a);
}
