// first.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define ADD 1
#define REMOVE 0
#define LIST 2
int main(int argc, char * * argv)
{
  int queue[MAX];
  int size = 0;
  int front = 0;
  int pos = 0;
  int val;
  int iChoice;
  int iNRead;
  int i;

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ADD:
        printf("Value to add: ");
        // Read the element, add it to the queue
        int valE;
        valE = scanf("%d", &val);
        if(size < MAX)
        {
            int pos1 = (front+size)%MAX;
            queue[pos1] = val;
            size++;
        }
      break;


      case REMOVE:
        // Print out the last element and remove it.
        if(size > 0)
        {
            val = queue[size-1];
            front = (front + 1)%MAX;
            printf("Removed element: %d\n", val);
            size--;
        }
        else
        {
            printf("Queue is empty");
        }
      break;

      
      case LIST:
        // Print out the queue elements
        for(i = 0; i < size; i++)
        {
            printf("%d\n", queue[i]);
        }
      break;
    }
    printf("Choice (1=add, 0=remove, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
