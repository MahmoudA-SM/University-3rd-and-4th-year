// first.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define PUSH 1
#define POP 0
#define LIST 2
int main(int argc, char* argv[])
{
  int stack[MAX];
  int size = 0;
  int val;
  int iChoice;
  int iNRead;
  int counter;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Value to add: ");
        // Read the element, add it to the stack
        scanf("%d", &val);
        if (size < MAX) {
            stack[size] = val;
            size++;
        }
      break;
      case POP:
      // Print out the last element and remove it.
          if (size == 0)
          {
              printf("There is nothing in the stack");
          }
          printf("%d\n", stack[size-1]);
          size--;
      break;
      case LIST:
        // Print out the stack elements
		counter = size;
          if (size == 0)
          {
              printf("The stack is empty");
          }
          else
          {
              while (counter > 0)
              {
                  printf("%d ", stack[counter-1]);
                  counter--;
              }
          }
      break;
    }
    printf("Choice (1=add, 0=remove, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
