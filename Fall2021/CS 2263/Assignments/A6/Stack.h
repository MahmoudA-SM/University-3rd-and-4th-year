#ifndef STACK_H
#define STACK_H
#include "Point2D.h"

typedef struct pt2link
{
    Point2D *payload;
    struct pt2link* next;
} PtLink, *pPtLink;

PtLink *mallocStackElement();

void freeStackELement(PtLink* pt);

PtLink *createStackElement(int x, int y);

PtLink *pushtoStack(PtLink *topElement, int x, int y);

void popStackElement(PtLink *topElement);

void reportStackElements(PtLink *start, PtLink *topElement, int size);

void peekStack(PtLink *topElement);
#endif