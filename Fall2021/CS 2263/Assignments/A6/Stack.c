#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stack.h"
#include "Point2D.h"

PtLink *mallocStackElement()
{
	PtLink *link = (PtLink *)malloc(sizeof(PtLink));
	link->payload = mallocPoint2D();
	return link;
}

void freeStackELement(PtLink *pt)
{
	free(pt->payload);
	free(pt);
}

PtLink *createStackElement(int x, int y)
{
	PtLink *point = mallocStackElement();

	point->payload->y = y;
	point->payload->x = x;

	return point;
}

PtLink *pushtoStack(PtLink *topElement, int x, int y)
{

	topElement->next = mallocStackElement();
	PtLink *nxt = topElement->next;

	nxt->payload->y = y;
	nxt->payload->x = x;

	return nxt;
}

void popStackElement(PtLink *topElement)
{
	freeStackELement(topElement);
}

void peekStack(PtLink *topElement)
{
	printf("(%d,%d)\n", topElement->payload->x, topElement->payload->y);
}

void reportStackElements(PtLink *start, PtLink *topElement, int size)
{
	int i, j; // loop variables

	for (i = size; i > 0; i--)
	{

		printf("(%d,%d)\n", topElement->payload->x, topElement->payload->y);
		size--;
		topElement = start;
		for (j = size; j > 1; j--)
		{
			topElement = topElement->next;
		}
	}
}