#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    char *inputArray = (char *)malloc(sizeof(char) * 100000);
    char *inputArrayC = inputArray;
    char **inputArrayp = (char **)malloc(sizeof(char *) * 100000);
    int *occurance = (int *)malloc(sizeof(int) * 100);
    *inputArrayp = inputArray;
    int counter = 0;

    char *inputArrayCT;
    char input = fgetc(f);
    while (input != EOF)
    {
        *inputArrayC = input;
        inputArrayC++;
        input = fgetc(f);
        counter++;
    }
    inputArrayC = inputArray;
    inputArrayCT = inputArrayC;
    char *inputArrayCC = inputArrayC;
    int i = 0;
    while (i < counter)
    {
        while(*inputArrayCT != '>')
        {
            inputArrayCT++;
        }
        if (*inputArrayC == '<')
        {
            inputArrayCC = inputArrayC+1;
            inputArrayC = inputArray;
            if (inputArrayCC > inputArrayC && inputArrayCC < inputArrayCT)
            {
                printf("%c", *inputArrayCC);
                inputArrayCC++;
            }
             
        }
        i++;
    }
}