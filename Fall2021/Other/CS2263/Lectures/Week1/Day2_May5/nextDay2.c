#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 'b';
    int num = 11;
    float num1 = 14.567;
    double num2 = 10.0;

    printf("The size of the character is %d\n", sizeof(ch));
    printf("The size of the int is %d\n", sizeof(num));
    printf("The size of the float is %d\n", sizeof(num1));
    printf("The size of the double is %d\n", sizeof(num2));
}