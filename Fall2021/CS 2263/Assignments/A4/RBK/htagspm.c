#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tagc;

void finallydisplay()
{
    char* counter = (char*) malloc(sizeof(char)*100);
    char** tagoccurance1 = (char**) malloc(sizeof(char*)*100);
    char** tagoccurance2 = (char**) malloc(sizeof(char*)*100);
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
