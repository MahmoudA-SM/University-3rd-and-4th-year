#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "Stack.h"
#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 3
int main(int argc, char *argv[])
{
  int iChoice;
  int iNRead;
  pPtLink start;
  pPtLink curr;
  int size = 0, x, y;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while (iNRead == 1)
  {
    switch (iChoice)
    {
    case PUSH:
      printf("Enter the x and y values of the point separated by a whitespace: "); // Obviously you need to read the x and y values
      // Read the element, add it to the stack
      scanf("%d %d", &x, &y);

      if (size == 0)
      {
        start = createStackElement(x, y);
        curr = start;
      }
      else
      {
        curr = pushtoStack(curr, x, y);
      }

      printf("Point pushed\n");
      size++;

      break;
      
    case POP:
      // Pop the Point2D and print it out.
      if (size <= 0)
      {
        printf("The stack is empty. Nothing to pop. -_- -_-\n");
      }
      else
      {
        popStackElement(curr);
        size--;
        curr = start;
        int i;
        for (i = size; i > 1; i--)
        {
          curr = curr->next;
        }
        printf("Popped top element successfully.\n");
      }
      break;
    case LIST:
      // Print out the stack elements
      if (size <= 0)
      {
        printf("The stack is empty. -_- -_- \n");
      }
      else
      {
        reportStackElements(start, curr, size);
      }
      break;
    case PEEK:
      // Print out the next value to be popped.

      if (size <= 0)
      {
        printf("The stack is empty. -_- -_- \n");
      }
      else
      {
        peekStack(curr);
      }
      break;
    default:
      return 0;
    }
    printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
