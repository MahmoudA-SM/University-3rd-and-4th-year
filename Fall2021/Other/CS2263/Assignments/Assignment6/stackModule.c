#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pt2link
{    

    Point2D* payload;    
    Struct pt2link* next; 

}PtLink, *pPtLink;


void display(pPointStack pCLThis)
{
    pPtLink variable;
    variable = pCLThis->head;

    if(variable == (pPtLink)NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while(variable != (pPtLink)NULL)
        {
            DisPoint(variable->payload);
            temp = temp->next;
        }
    }
}
void stackPush(pPointS pCLThis, Point2D* pt)
{
    pPtLink var = (pPtLink)malloc(sizeof(PtLink));
    var = pCLThis->head;
    pPtLink anotherVar = (pPtLink)malloc(sizeof(PtLink));

    if(var == (pPtLink)NULL)
    {
        anotherVar->payload = copyPoint2D(pt);
        anotherVar->next = (pPtVar)NULL;
        pCLThis->head
        var->next = anotherVar;
        return;
    }

    while(var->next != (pPtLink)NULL)
    {
        var = var->next;
    }
    anotherVar->payload = copyPoint2D(p);
    anotherVar->next = (pPtLink)NULL;

    var->next = anotherVar;
}