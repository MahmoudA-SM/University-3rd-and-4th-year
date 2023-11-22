#include <stdio.h>
#include <stdlib.h>
int factorial(int n);
int main() {
    int n = 6;
    printf("%d", factorial(n));
    return 0;
}
int factorial(int n) {
    if (n >=1)
        return n*factorial(n-1);
    else
        return 1;
}