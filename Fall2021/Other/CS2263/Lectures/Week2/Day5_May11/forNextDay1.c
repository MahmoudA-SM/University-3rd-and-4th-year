#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 2;
    int* pi;
    pi = &i;
    printf("%p: %i", &i, i);
    printf("%p: %i\n", pi, *pi);
    *pi = 4;
    printf("%pi: %i", &i, i);
    printf("%pi: %i\n", pi, *pi);
}