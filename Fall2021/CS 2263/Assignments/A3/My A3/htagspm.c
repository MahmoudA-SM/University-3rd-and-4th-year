#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int tc;
char *occurance1[150];
char *occurance2[150];
char c[100];
void finallydisplay()
{
    int i;
    for (i = 0; i < tc; i++)
    {
        if (*(occurance1 + i) != NULL)
        {
            char *ptr2;
            ptr2 = *(occurance1 + i);
            char *ptr3;
            ptr3 = *(occurance2 + i);
            int loopsy = 0;
            while (*ptr2 != *ptr3)
            {
                loopsy++;
                *ptr2++;
            }
            printf("%.*s --> %d \n", loopsy, *(occurance1 + i), *(c + i));
        }
    }
}