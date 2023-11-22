#include <stdio.h>
#include <stdlib.h>


int main() {
	int input;
	printf("Enter the int you want to check whether it is a prime: ");
	scanf("%d", &input);
	if (isPrime(input) == 0)
	{
		printf("%d is not a prime number\n", input);
	}
	else
	{
		printf("%d is a prime number\n", input);
	}
	return EXIT_SUCCESS;
}
