#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const **argv)
{
    unsigned char ch[250];

    unsigned int var;

    int num;

    FILE *fptr = fopen(argv[1], "rb");
    FILE *fptr2 = fopen(argv[2], "w");

    fseek(fptr, 0, SEEK_END);

    num = ftell(fptr);

    fseek(fptr, 0, SEEK_SET);

    while(fread(&num, sizeof(char), 1, fptr) == 1)
    {
        fread(&ch, sizeof(char), 1, fptr);
        fread(&var, sizeof(int), 1, fptr);

        fprintf(stderr, "%s %d\n", ch, var);
    }

    fclose(fptr);

}