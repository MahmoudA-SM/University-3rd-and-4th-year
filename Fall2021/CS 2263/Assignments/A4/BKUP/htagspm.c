#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int tagc;
extern char *tagoccurance1[150];
extern char *tagoccurance2[150];
extern char counter[100];

void finallydisplay()
{
    
    int i;
    for (i = 0; i < tagc; i++)
    {
        
        if (*(tagoccurance1 + i) != NULL)
        {
            char *ptr2;
            ptr2 = *(tagoccurance1 + i);
            char *ptr3;
            ptr3 = *(tagoccurance2 + i);
            int loopsy = 0;
            
            while (*ptr2 != *ptr3)
            {
            
                loopsy++;
                *ptr2++;
            }
            
            printf("%.*s --> %d \n", loopsy, *(tagoccurance1 + i), *(counter + i));
        }
    }
}
