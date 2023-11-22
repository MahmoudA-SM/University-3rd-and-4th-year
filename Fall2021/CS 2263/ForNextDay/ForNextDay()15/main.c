#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length;
int i;
char *getString()
{
    char *s;
    fgets(s, 100, stdin);
    length = strlen(s);
    char *sArray[length];
    return s;
}

int main(int argc, char *argv[])
{

    FILE *f = fopen(argv[1], "w");
    if (f == (FILE *)NULL)
    {
        printf("Error opening %s\n", argv[1]);
    }
    char *s = getString();
    fputString(f, s);
    int j = 0;
    while (j < 4)
    {
        s = getString();
        fputString(f, s);
        j++;
    }
    fclose(f);
    return EXIT_SUCCESS;
}
