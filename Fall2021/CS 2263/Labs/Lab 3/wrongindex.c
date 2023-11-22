/*
 * wrongindex.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int x = -2;
  int arr[] = {0, 1, 2, 3, 4};
  int y = 15;
  printf("& x      = %p, & y      = %p\n", & x, & y);
  printf("& arr[0] = %p, & arr[4] = %p\n", & arr[0], 
	 & arr[4]);
  printf("x = %d, y = %d\n", x, y);
  printf("X memory address: %p\n", &x);
  printf("Y memory address: %p\n", &y);
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("The memory address of array[%d] is %p\n", i, &arr[i]);
  }
  arr[-1] = 7;
  arr[5]  = -23;
  printf("x = %d, y = %d\n", x, y);
  printf("X memory address: %p\n", &x);
  printf("Y memory address: %p\n", &y);
  for (i = 0; i < 5; i++)
  {
    printf("The memory address of array[%d] is %p\n", i, &arr[i]);
  }
  arr[6]  = 108;
  printf("x = %d, y = %d\n", x, y);
  printf("X memory address: %p\n", &x);
  printf("Y memory address: %p\n", &y);
  for (i = 0; i < 5; i++)
  {
    printf("The memory address of array[%d] is %p\n", i, &arr[i]);
  }
  arr[7]  = -353;
  printf("x = %d, y = %d\n", x, y);
  printf("X memory address: %p\n", &x);
  printf("Y memory address: %p\n", &y);
  for (i = 0; i < 5; i++)
  {
    printf("The memory address of array[%d] is %p\n", i, &arr[i]);
  }
  return EXIT_SUCCESS;
}