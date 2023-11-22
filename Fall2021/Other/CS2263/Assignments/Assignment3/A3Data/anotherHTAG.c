#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TAG_SIZE 10

int main(int argc, char **argv)
{
    FILE *fptr;

    char arr[10] = "";
    int countTag[100];
    char tags[100][MAX_TAG_SIZE];

    int count = 0;
    
    char* fName = argv[1];

    fptr = fopen(fName, "r");

    int i;
    for(i = 0; i < 100; i++)
    {
        countTag[i] = 0;
    }

    if(fptr != NULL)
    {
        while(!feof(fptr))
        {
            char var = fgetc(fptr);

            if(var == '<' && !feof(fptr))
            {
                char var1 = fgetc(fprt);

                if(var1 != '/')
                {
                    int num;
                    num = 0;

                    strcpy(arr, "");

                    while(var1 != 10 && var1 != '>' && var1 != ' ' && !feof(ptr))
                    {
                        arr[num] = var1;
                        var1 = fgetc(fptr);
                        num++;
                    }

                    arr[num] = '\0';

                    int num1 = 1;
                    
                    int j;

                    for(j = 0; j < count; j++)
                    {
                        if(strcmp(tags[j], arr) == 0)
                        {
                            countTag[j]++;
                            num1++;
                        }
                    }

                    if(num1 == 1)
                    {
                        strcpy(arr[count])
                    }
                }
            }
        }
    }
}