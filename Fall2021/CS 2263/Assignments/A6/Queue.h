#ifndef QUEUE_H
#define QUEUE_H
#include "Point2D.h"

typedef struct pt2link
{
	Point2D* payload;
	struct pt2link* next;
}PtLink, *pPtLink;


PtLink* mallocQueueElement();

void freeQueueElement(PtLink *pt);

void freeQueueELement(PtLink* pt);

PtLink* createQueueElement(int x, int y);

PtLink* enqueueElement(PtLink* currentP, int x, int y);

PtLink* dequeueElement(PtLink* currentP);

void reportQueueElements(PtLink* start, int size);

void peekQueue(PtLink* currentP);

#endif
