// swap.c
/*
 */
#include <stdio.h>
#include <stdlib.h>
void swap(int* i, int* j);

int main(int argc, char* argv[]) {
   int i = 10;
   int j = 99;
   printf("i = %d; j = %d\n", i, j);
   swap(&i,&j);
   printf("i = %d; j = %d\n", i, j);
   return EXIT_SUCCESS;
}
void swap(int* i, int* j) {
   int swap;
   swap = *i;
   *i = *j;
   *j = swap;
}
