#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100000
#define TOTALTAGS 100
#define TAGSIZE 50

void memory(char* var1, char** tagList, int* counter)
{
    free(var1);

    for(int i = 0; i < TOTALTAGS; i++)
    {
        free(tagList[i]);
    }
    free(tagList); //freeing char tagList array
    free(counter); //freeing int counter array
}


void display(char** tag, int* countingTag)
{
    for(int i = 0; i < TOTALTAGS; i++)
    {
        if(countingTag[i] != -1)
        {
            printf("%s %d\n", tag[i], countingTag[i]); 
        }
    }
}

void tagCounter(char* charac1, char** anotherCharac, int* counting)
{
    int var;
    int i = 0;
    for(i = 0; i < TOTALTAGS; i++)
    {
        if(anotherCharac[i] == NULL)
        {
            break;
        }
        else if(strncmp(charac1, anotherCharac[i], strlen(charac1)) == 0)
        {
            var = 1;
            break;
        }
    }

    if(var)
    {
        counting[i] = counting[i] + 1;
    }
    else
    {
        anotherCharac[i] = charac1;
        counting[i] = 1;
    }
}


int fileReader(char* charac, char** tag, int* countTag)
{
    int len, count, index;
    char* ptr;

    if((len = read(0, charac, MAXSIZE)))
    {
        for(int i = 0; i < len; i++)
        {
            if(count == 0)
            {
                if(charac[i] == '<')
                {
                    ptr = (char*)malloc(TAGSIZE);
                    memset(ptr, '\0', TAGSIZE);
                    count = 1;
                }
            }
            else
            {
                if(charac[i] == '>' || charac[i] == '/'|| charac[i] == ' ')
                {
                    count = 0;
                    index = 0;

                    if(charac[i] != '/')
                    {
                        tagCounter(ptr, tag, countTag);
                    }
                    else
                    {
                        free(ptr);
                    }
                }
                else
                {
                    ptr[index++] = charac[i];
                }
            }
        }
    }
}


int main(int argc, char** argv)
{
    char* cPtr = NULL;
    char** namingIsHard = NULL;
    int* variable = NULL;

    cPtr = (char*)malloc(sizeof(char)*MAXSIZE+1);
    namingIsHard = (char**)malloc(sizeof(char*)*TOTALTAGS);
    variable = (int*)malloc(sizeof(int)*TOTALTAGS);
    memset(cPtr, '\0', MAXSIZE+1);

    for(int i = 0; i < TOTALTAGS; i++)
    {
        namingIsHard[i] = NULL;
        variable[i] = -1;
    }

    fileReader(cPtr,namingIsHard,variable);
    display(namingIsHard, variable);
    memory(cPtr,namingIsHard, variable);

    return EXIT_SUCCESS;
}