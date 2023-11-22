//This program prints the size of different data types
//@author Mahmoud Moustafa; ID:3648276
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
    char c;
    int i;
    float f;
    double d;
    printf("The size of char is %d byte\n", sizeof(c));
    printf("The size of int is %d bytes\n", sizeof(i));
    printf("The size of float is %d bytes\n", sizeof(f));
    printf("The size of double is %d bytes\n", sizeof(d)); 

    return EXIT_SUCCESS;
}
