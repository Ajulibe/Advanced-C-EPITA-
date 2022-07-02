// #include "basic.h"
#include <stdio.h>
#include <stdlib.h>

void printName() {
  char name[] = "Alexandra Abramov";
  char DOB[] = "July 14, 1975";
  char mobile[] = "99 - 9999999999";
  printf("Name   :  %s\n", name);
  printf("DOB    :  %s\n", DOB);
  printf("Mobile :  %s\n", mobile);
}

// 5. Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches. Go to the editor
// Expected Output:
// Perimeter of the rectangle = 24 inches
// Area of the rectangle = 35 square inches

int computeArea(int a, int b) {
  int res;
  res = a * b;
  return res;
}

// 6. Write a C program to compute the perimeter and area of a circle with a given radius. Go to the editor
// Expected Output:
// Perimeter of the Circle = 37.680000 inches
// Area of the Circle = 113.040001 square inches

void computerPerimeterandArea(long double r, int size) {
  long double perimeter;
  long double *my_array = (long double *)malloc(size * sizeof(int));
  long double area;
  perimeter = 2 * 2.142 * r;
  area = 3.142 * r * r;
  my_array[0] = perimeter;
  my_array[1] = area;
  for (int i = 0; i < size; i++) {
    printf("%Lf", my_array[i]);
  }
}

int main() {
  // printName();
  // int result = computeArea(35, 24);
  // printf("%d", result);
  // computerPerimeterandArea(12.99999, 2);
  int a;
  int b;
  // acceptAndcalculate();
  int firstInteger;
  int secondInterger;
  printf("Type a number and press enter: \n");
  scanf("Enter the first integer %d", &firstInteger);
  printf("Type another number and press enter: \n");
  scanf("Enter the first integer %d", &secondInterger);

  return 0;
}

// 10. Write a C program that accepts two integers from the user and calculate the product of the two integers. Go to the editor
// Test Data :
// Input the first integer: 25
// Input the second integer: 15
// Expected Output:
// Product of the above two integers = 375

void acceptAndcalculate() {
  int firstInteger;
  int secondInterger;
  scanf("Enter the first integer %d", &firstInteger);
  scanf("Enter the first integer %d", &secondInterger);
  // printf("%d", firstInteger);
  // printf("%d", secondInteger);
}