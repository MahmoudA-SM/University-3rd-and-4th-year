#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int count = 0;

void create(pPtLink link)
{
    link = NULL;
}

/* Count stack elements */
void stack_count()
{
    printf("\n No. of points in stack : %d", count);
}

/* Push data into stack */
pPtLink push(pPtLink link, double data1, double data2)
{

    if ( link == NULL)
    {
        link =(pPtLink)malloc(sizeof(pPtLink));
        if(link != (pPtLink)NULL)
        {
            link->payload->x = data1; //SEGMENTATION FAULT
            link->payload->y = data2;
            link->next = NULL;
        }
//link->payload->x = data1;
//link->payload->y = data2;
//link->next = NULL;
    }
    else
    {
        pPtLink temp;
        temp =(pPtLink)malloc(sizeof(pPtLink));
        temp->next = link;
        temp->payload->x = data1;
        temp->payload->y = data2;
        link = temp;
    }
    count++;

    return link;
}

/* Display stack elements */
void display(pPtLink link)
{
    pPtLink current;
    current = link;

    if (current == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (current != NULL)
    {
        printf("%lf %lf ", current->payload->x, current->payload->y);
        current = current->next;
    }
}

