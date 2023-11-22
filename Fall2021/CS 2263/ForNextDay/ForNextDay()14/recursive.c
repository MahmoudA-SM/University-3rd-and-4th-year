#include <stdio.h>
int fac(int n)
{
    int val;
    if (n == 0)
    {
        printf("Top of the stack: %p\n", &n);
        val = 1;
        return val;
    }
    val = n * fac(n - 1);
    return val; // RL2
}
int main(int argc, char *argv[])
{
    int x = 15;
    int f = fac(x);
    printf("Bottom of the stack: %p\n", &x);  
    printf("%d\n", f); // RL1
}