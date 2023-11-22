#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *str1;
char *str2;
int tagc = 0;

void fileopen(char *x[]);
void finallydisplay();

int main(int argc, char *argv[])
{
    char* input = (char*) malloc(sizeof(char)*100000);
    char* counter = (char*) malloc(sizeof(char)*100);
    char** tagoccurance1 = (char**) malloc(sizeof(char*)*100);
    char** tagoccurance2 = (char**) malloc(sizeof(char*)*100);
    char *ptr2;

    fileopen(argv);
    int len = strlen(input);
    int x = 0;

    // printf("%d \n", len);
    char *inputptr2 = input;
    int y = 0;

    int i;
    for (i = 0; i < len; i++)
    {

        if (*(inputptr2 + i) == '<' && *(inputptr2 + i + 1) != '/' && *(inputptr2 + i + 1) != '!')
        {
            printf("in");
            *(tagoccurance1 + x) = inputptr2 + i + 1;
            x++;
            tagc++;
        }

    }
    int yt = 0;
    char *end;

    int h = 0;

    for (i = 0; i < tagc; i++)
    {

        char *ptr;
        ptr = *(tagoccurance1 + i);

        while (*ptr != '\0')
        {

            if (*ptr == ' ' || *ptr == '>')
            {

                *(tagoccurance2 + h) = ptr;
                *ptr++;
                h++;
                break;
            }
            else
                *ptr++;
        }
    }

    int soup;
    for (soup = 0; soup < tagc; soup++)
    {

        ptr2 = *(tagoccurance1 + soup);
        char *ptr3;
        ptr3 = *(tagoccurance2 + soup);
        int loopsy = 0;

        while (*ptr2 != *ptr3)
        {
            loopsy++;
            *ptr2++;
        }

        char *ptr6;
        ptr6 = *(tagoccurance1 + soup);
        char *pleasework = (char *)malloc(loopsy);
        strncpy(pleasework, ptr6, loopsy);

        int stew;
        for (stew = 0; stew < tagc; stew++)
        {
            char *ptrq;
            ptrq = *(tagoccurance1 + stew);
            char *ptrw;
            ptrw = *(tagoccurance2 + stew);
            int loopsydoopsy = 0;
            while (*ptrq != *ptrw)
            {
                loopsydoopsy++;
                *ptrq++;
            }

            char *ptrg;
            ptrg = *(tagoccurance1 + stew);
            char *mightwork = (char *)malloc(loopsydoopsy);
            strncpy(mightwork, ptrg, loopsydoopsy);

            if (strcmp(pleasework, mightwork) == 0)
                *(counter + stew) = *(counter + stew) + 1;
            else
            {
            }
        }
    }

    for (i = 0; i < tagc; i++)
    {
        if (*(tagoccurance1 + i) == NULL)
            continue;
        else
        {
            int j;
            for (j = i + 1; j < tagc; j++)
            {

                if (*(tagoccurance1 + j) == NULL)
                    continue;
                else
                {
                    ptr2 = *(tagoccurance1 + i);
                    char *ptr3;
                    ptr3 = *(tagoccurance2 + i);
                    int loopsy = 0;
                    while (*ptr2 != *ptr3)
                    {
                        loopsy++;
                        *ptr2++;
                    }
                    char *ptr6;
                    ptr6 = *(tagoccurance1 + i);
                    str1 = (char *)malloc(loopsy);
                    strncpy(str1, ptr6, loopsy);
                    char *ptrq;
                    ptrq = *(tagoccurance1 + j);
                    char *ptrw;
                    ptrw = *(tagoccurance2 + j);
                    int loopsydoopsy = 0;
                    while (*ptrq != *ptrw)
                    {
                        loopsydoopsy++;
                        *ptrq++;
                    }
                    char *ptrg;
                    ptrg = *(tagoccurance1 + j);
                    str2 = (char *)malloc(loopsydoopsy);
                    strncpy(str2, ptrg, loopsydoopsy);
                    if (strcmp(str1, str2) == 0)
                    {

                        *(tagoccurance1 + j) = NULL;
                        *(tagoccurance2 + j) = NULL;
                    }
                }
            }
        }
    }

    finallydisplay();

    return EXIT_SUCCESS;
}
