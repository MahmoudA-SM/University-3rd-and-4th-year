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
  int counter;
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
        scanf("%d", &val);
        if (size < MAX)
        {
        	pos = (front+size) % MAX;
        	queue[pos]= val;
        	size++;
		}
      break;
      case REMOVE:
      // Print out the last element and remove it.
      if (size == 0)
      {
      	printf("There is nothing in the queue\n");
	  }
      if (size > 0)
      {
      	printf("%d\n", queue[front]);
      	val = queue[front];
      	front = (front+1) % MAX;
      	size--;
	  }
      break;
      case LIST:
      // Print out the queue elements
      counter = 0;
      if (size == 0)
      {
      	printf("The queue is empty\n");
	  }
	  else
	  {
	  	while (counter < size)
	  	{
	  		printf("%d\n", queue[front + counter]);
	  		counter++;
		}
	  }
      break;
    }
    printf("Choice (1=add, 0=remove, 2=list): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
