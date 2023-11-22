#include <stdlib.h>
#include <stdio.h>


int tag(char* array)
{
    
}

int main(int argc, int* argv[])
{
    char inputArray[100000];
    char* inputArrayP = inputArray;
    char inputChar = fgetc(stdin);
    char* tagArray [100];
    int occurancesArray[100];
    char* inputArrayPC = inputArrayP++;;
    while(inputChar != EOF)
    {
        *inputArrayP = inputChar;
        inputChar = fgetc(stdin);
        inputArrayP++;
    }
    
    if(*inputArrayP == '<' && *inputArrayPC != '!' && *inputArrayPC != ' ')
    {
        
    }
    inputArrayPC = inputArrayPC++;

}