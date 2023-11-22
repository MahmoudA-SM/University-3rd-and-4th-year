#include <stdio.h>
#include <stdlib.h>
int multiply(int num1, int num2);
int main()
{
    int var1;
    int var2;
    int product;

    printf("In main(): ");
    printf("\n");
    printf("Location of var1 in the stack: %p\n", &var1);
    printf("Location of var2 in the stack: %p\n", &var2);
    printf("Location of product in the stack: %p\n", &product);
    printf("\n");

    printf("Enter two numbers: ");
    scanf("%d %d", &var1, &var2);

    product = multiply(var1, var2);
    printf("The product is: %d\n", product);
}

int multiply(int num1, int num2)
{
    int product;
    printf("In multiply(): ");
    printf("\n");
    printf("Location of num1 in the stack: %p\n", &num1);
    printf("Location of num2 in the stack: %p\n", &num2);
    printf("Location of product in the stack: %p\n", &product);
    product = num1*num2;
    return product;
}