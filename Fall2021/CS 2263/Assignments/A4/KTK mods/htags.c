#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100000
#define TOTAL_TAGS 100
#define MAX_TAG_SIZE 30

void display(char **tagArr, int *tagCounter)
{
    printf("Tag\tCount");
    printf("\n");
    int i;
    for(i = 0;i < TOTAL_TAGS; i++)
    {
        if(tagCounter[i]!=-1)
        {
            printf("%s \t %d\n",tagArr[i], tagCounter[i]);
        }
    }
}


void tagCounter(char *charac, char **tagArr, int *counter)
{
    int i = 0;
    int tag = 0;

    for(i = 0; i < TOTAL_TAGS; i++)
    {
        if(tagArr[i] == NULL)
        {
            break;
        }
        else if(strncmp(charac, tagArr[i], strlen(charac)) == 0)
        {
            tag = 1;
            break;
        }
    }

    if (tag)
    {
        counter[i] = counter[i]+1;
    }
    else
    {
        tagArr[i] = charac;
        counter[i] = 1;
    }
}


void memoryFreeing(char *ch, char **tagsArr, int *counting)
{
    free(ch);
    int i;
    for(i = 0;i < TOTAL_TAGS;i++)
    {
        free(tagsArr[i]); //freeing each element of tagsArr array
    }
    free(tagsArr); //freeing tagsArr array
    free(counting); //freeing counting Array
}


int fileReader(char *charac1, char **tag, int *counter)
{
    int len = 0;
    int num = 0;
    char *tagPtr = NULL;
    int indexPos = 0;

   if ((len = read(0, charac1, MAX_SIZE)))
   {
     int i;
       for(i = 0; i < len; i++)
       {
            if (num == 0)
            {
                //checking for HTML tags
                if(charac1[i] == '<')
                {
                    tagPtr = (char *)malloc(MAX_TAG_SIZE);
                    memset(tagPtr, '\0', MAX_TAG_SIZE);
                    num = 1;
                }
            }
            else
            {
                if(charac1[i] == '>' || charac1[i] == '/'|| charac1[i] == ' ')
                {
                    num = 0;
                    indexPos = 0;
                    if(charac1[i] !='!')
                    {
                        tagCounter(tagPtr, tag, counter);
                    }
                    else
                    {
                        free(tagPtr);
                    }
                }
                else
                {
                    tagPtr[indexPos++] = charac1[i];
                }
            }
       }
   }
}


int main()
{
    char *input=NULL;
    char** tagPtr=NULL;
    int *tagsCounter=NULL;

    input = (char *)malloc(sizeof(char) * MAX_SIZE+1);
    tagPtr = (char **) malloc(sizeof(char *) * TOTAL_TAGS);
    tagsCounter = (int *) malloc(sizeof(int) * TOTAL_TAGS);
    memset(input,'\0', MAX_SIZE+1);
    int i;
    for(i = 0; i < TOTAL_TAGS; i++)
    {
        tagPtr[i]=NULL;
        tagsCounter[i]=-1;
    }

    fileReader(input, tagPtr, tagsCounter); //reading the file
    display(tagPtr, tagsCounter); //printing the output
    memoryFreeing(input, tagPtr, tagsCounter); //freeing all the heap memory
    return EXIT_SUCCESS;
}
