#include <stdio.h>
#include <stdlib.h>

int fac(int n) 
{
    int val;
    if (n == 0) 
    {
        val = 1; 
        return val;
    }
    val = n * fac(n-1); return val; // RL2
}


int main(int argc, char* argv[])
{
    int x = 15;
    int f = fac(x);
    printf("%d\n", f); // RL1
    printf("\n");
    printf("Address of number: %p\n", &x);
    printf("Address of factorial: %p\n", &f);
}