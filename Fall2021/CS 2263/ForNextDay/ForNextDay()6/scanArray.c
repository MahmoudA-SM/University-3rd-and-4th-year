#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int array[size];
	scanfIntArray(array, size);
	return EXIT_SUCCESS;
}

int scanfIntArray(int a[], int n) {
	int i = 0;
	while (i < n)
	{
		printf("Enter the element to be added to the array: ");
		scanf("%d", &a[i]);
		i++;
	}
	max_min(a, n, a[0], a[1]);
	return printf("There are %d elements in the array.\n", i);
}

void max_min(int a[], int n, int *mx, int *mn)
{
	mn = &a[0];
	mx = &a[1];
	int i = 0;
	while (i < n)
	{
		if (*mn > a[i]) {
			*mn = a[i];
		}
		if (*mx < a[i])
		{
			*mx = a[i];
		}
		i++;
	}
	printf("Min: %d; Max: %d\n", *mn, *mx);
}
