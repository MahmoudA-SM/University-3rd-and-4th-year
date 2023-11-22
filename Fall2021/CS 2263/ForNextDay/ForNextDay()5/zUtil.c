#include <stdio.h>
#include <stdlib.h>

void zero(int* pi) {
	*pi = 0; 
}




int main() {
	int pi = 3;
	printf("Pi before modification: %d\n", pi);
	printf("Pi before modification: %p\n", &pi);
	zero(&pi);
	printf("Pi after modification: %d\n", pi);
	printf("Pi after modification: %p\n", &pi);
	return EXIT_SUCCESS;
}
