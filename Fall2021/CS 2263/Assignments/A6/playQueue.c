#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "Point2D.h"

#define DEQUEUE 0
#define ENQUEUE 1
#define LIST 2
#define PEEK 3

int main(int argc, char **argv)
{
  int iChoice;
  int iNRead;

  pPtLink curr;
  pPtLink start;

  int size = 0, x, y;

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while (iNRead == 1)
  {
    switch (iChoice)
    {
    case ENQUEUE:
      printf("Enter the x and y values of the point separated by a whitespace: ");
      scanf("%d %d", &x, &y);

      if (size == 0)
      {
        start = createQueueElement(x, y);
        curr = start;
      }
      else
      {
        curr = enqueueElement(curr, x, y);
      }

      printf("Point enqueued\n");
      size++;

      break;

    case DEQUEUE:
      // dequeue the Point2D and print it out.
      if (size <= 0)
      {
        printf("The queue is empty. Nothing to dequeue. -_- -_-\n");
      }
      else
      {
        start = dequeueElement(start);
        size--;
        printf("Dequeued the first element.\n");
      }
      break;

    case LIST:
      // Print out the queue elements.
      if (size <= 0)
      {
        printf("The queue is empty. -_- -_- \n");
      }
      else
      {
        reportQueueElements(start, size);
      }
      break;

    case PEEK:
      // Print out the next value to be dequeue.
      if (size <= 0)
      {
        printf("The queue is empty. -_- -_- \n");
      }
      else
      {
        peekQueue(start);
      }
      break;

    default:
      return 0;
    }
    printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}