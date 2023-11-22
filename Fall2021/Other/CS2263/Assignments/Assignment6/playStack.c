// playStack.c
#include <stdio.h>
#include <stdlib.h>
#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 2
int main(int argc, char* argv[])
{
  int iChoice;
  int iNRead;
  int x;
  int y;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the stack
        scanf("%d %d\n", &x, &y);
      break;
      case POP:
      // Pop the Point2D and print it out.
      break;
      case LIST:
        // Print out the stack elements
      break;
      case PEEK:
        // Print out the next value to be popped.
      break;
      default: 
        return 0;
    }
    printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
