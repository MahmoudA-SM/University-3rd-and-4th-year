#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Queue.h"
#include "Point2D.h"

PtLink *mallocQueueElement()
{
    PtLink *link = (PtLink *)malloc(sizeof(PtLink));
    link->payload = mallocPoint2D();
    return link;
}

void freeQueueElement(PtLink *pt)
{
    free(pt->payload);
    free(pt);
}

PtLink *createQueueElement(int x, int y)
{
    PtLink *point = mallocQueueElement();

    point->payload->y = y;
    point->payload->x = x;

    return point;
}

PtLink *enqueueElement(PtLink *pt, int x, int y)
{
    pt->next = mallocQueueElement();
    PtLink *nxt = pt->next;

    nxt->payload->y = y;
    nxt->payload->x = x;

    return nxt;
}

PtLink *dequeueElement(PtLink *pt)
{
    PtLink *nxt = pt->next;
    freeQueueElement(pt);
    return nxt;
}

void peekQueue(PtLink *currentP)
{
    int x = currentP->payload->x;
    int y = currentP->payload->y;
    printf("(%d,%d)\n", x, y);
}

void reportQueueElements(PtLink *start, int size)
{
    PtLink *currentP = start;
    int i; // loop variable
    for (i = size; i > 0; i--)
    {
        int x = currentP->payload->x;
        int y = currentP->payload->y;
        printf("(%d,%d)\n", x, y);
        currentP = currentP->next;
    }
}
