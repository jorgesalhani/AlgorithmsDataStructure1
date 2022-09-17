#include <stdio.h>

void funcao1(int x) {
  x = 30;
}

void funcao2(int *ptr) {
  *ptr = 30;
}

int main() {
  // Question 1
  // ==========
  /**
  int i = 10, j = 20, temp;
  int *p1, *p2;
  p1 = &i; 
  p2 = &j;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  printf("%d %d\n", *p1, *p2); // 20, 10
  return 0;
  */

  // Question 2
  // ==========
  /**
  int a[5] = {0,1,2,3,4};
  int *pa;
  printf("&pa = %p\n", pa);
  printf("&a = %p\n", a);
  // pa = &a[0];
  // printf("&pa = %p\n", pa);
  // pa = a;
  // printf("&pa = %p\n", pa);
  // printf("%d %d\n", a[2], *(a+2));
  printf("%p\n", a++);
  */

 // Question 3
 // ==========
 /**
 int mat[4], *p, x;
 printf("%p %p %d\n", p, &x, x);
 p = mat + 1; printf("%p\n", p);
//  p = mat++;
//  p = ++mat;
//  x = (*mat)++; printf("%d %d\n", *mat, x);
 x = *p(&mat++);
 */

  // Question 7
  // ==========
  /**
  int y = 20;
  funcao1(y);
  printf("%d\n", y);
  return 0;
  */

  // Question 8
  // ==========
  // int y = 20;
  // funcao2(&y);
  // printf("%d\n", y);
  // return 0;

  // Question 9
  // ==========
  // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
  // float *ptr1 = &arr[0];
  // float *ptr2 = ptr1 + 3;
  // printf("%f\n", *ptr2);
  // printf("%ld\n", ptr2 - ptr1);

  // Question 10
  // ===========
  // int arr[] = {10, 20, 30, 40, 50, 60};
  // int *ptr1 = arr;
  // int *ptr2 = arr + 5;
  // printf("%ld, ", (ptr2 - ptr1));
  // printf("%ld\n", (char*)ptr2 - (char*)ptr1);
  return 0;
}
