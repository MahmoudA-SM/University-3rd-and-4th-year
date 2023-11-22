/*
This program asks users for lower and upper limit input and
prints the prime numbers in the fibonacci sequence inclusive of
the limits
@author Mahmoud Moustafa; ID:3648276
*/
#include <stdio.h>
#include <stdlib.h>
int x1;
int x2;
int n;

int main() {
	printf("Enter the lower limit: ");
	scanf("%d", &x1);
	printf("Enter the upper limit: ");
	scanf("%d", &x2);
	n = x1;
	while (n <= x2)
	{
		if (isFib(n) && isPrime(n))
		{
			printf("%d ", n);
		}
		n++;
	}
	printf("\n");
	return EXIT_SUCCESS;
}
