#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"

int main(int argc, char* argv[])
{
    if(argc < 1)
    {
        int var = argc-1;

        char** ch = duplicateStringList(argv+1, var);

        int num = 0;

        while(ch != (char*)NULL && num < var)
        {
            printf("%s\n", ch[num]);
            num++;
        }
    }

    return 0;
}