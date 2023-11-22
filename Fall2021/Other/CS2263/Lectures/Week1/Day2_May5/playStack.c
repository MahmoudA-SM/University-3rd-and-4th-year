// first.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define PUSH 1
#define POP 0
#define LIST 2
int main(int argc, char* argv[])
{
    int top = -1;
    int count = 0;
    int i;
    int stack[MAX];
    int size = 0;
    int val;
    int iChoice;
    int iNRead;

  /* Processing loop */
  printf("Choice (1=push, 0=pop, 2=list): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Value to add: ");
        // Read the element, add it to the stack
        int valE;
        valE = scanf("%d", &val);

        if(valE != 1)
        {
          printf("Invalid input\n");
        }

        if(size < MAX)
        {
            stack[size] = val;
            size++;
        }

        else
        {
            printf("Error. Exceeding the MAX size");
        }
      break;

      case POP:
      // Print out the last element and remove it.
        if(size > 0)
        {
            val = stack[size - 1];
            printf("Removed element: %d\n", val);
            size--;
        }

        else
        {
          printf("Stack is empty");
        }
      break;
      case LIST:
        // Print out the stack elements
            for(i = 0; i < size; i++)
            {
                printf("\n%d", stack[i]);
                printf("\n");
            }
      break;
    }
    printf("Choice (1=push, 0=pop, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
