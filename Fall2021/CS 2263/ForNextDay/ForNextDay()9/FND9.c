#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("\nargc = %d\targc address: %p\n", argc, &argc);
    int i;
    for(i=0; i < argc ;i++)
    {
        printf("argument %d: %s\t address: %p\n", i, argv[i], &argv[i]);
    }
    printf("Address of argv: %p\n", &argv);
    printf("Address of *argv: %p\n", &*argv);
    printf("Address of **argv: %p\n", &**argv);
    printf("\n");
    return EXIT_SUCCESS;
}
