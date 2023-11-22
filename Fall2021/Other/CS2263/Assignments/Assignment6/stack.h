#ifndef STACK_H
#define STACK_H

typedef struct point2d
{
   double x;
   double y;

} Point2D;


typedef struct pt2link {
Point2D* payload;
struct pt2link* next;
}PtLink, *pPtLink;

void create(pPtLink link);
void stack_count();
pPtLink push(pPtLink link, double data1, double data2);
void display(pPtLink link);

#endif