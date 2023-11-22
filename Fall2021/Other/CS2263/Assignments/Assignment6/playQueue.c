// playQueue.c
#include <stdio.h>
#include <stdlib.h>
#define ENQUEUE 1
#define DEQUEUE 0
#define LIST 2
#define PEEK 3
int main(int argc, char * * argv)
{
  int val;
  int iChoice;
  int iNRead;

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ENQUEUE:
        printf("Point value to add:"); // Obviously you need to read the x and y values
        // Read the element, add it to the queue
      break;
      case DEQUEUE:
      // dequeue the Point2D and print it out.
      break;
      case LIST:
        // Print out the stack elements, 
      break;
      case PEEK:
        // Print out the next value to be dequeue.
      break;
      default: 
        return 0;
    }
    printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
