#include <stdio.h>
#include <stdlib.h>

int main() {
	int input;
	printf("Enter an int to check if it is in the Fibonacci sequence: ");
	scanf("%d", &input);
	if (isFib(input) == 0)
	{
		printf("%d is not in the Fibonacci sequence.\n", input);
	}
	else
	{
		printf("%d is in the Fibonacci sequence.\n", input);
	}
	return EXIT_SUCCESS;
}

