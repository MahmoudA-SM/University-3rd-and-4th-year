#include "myutils.h"
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int a = 4;
	int b = 10;
	printf("The smaller of a = %d and b = %d is: %d ", a, b, min(a,b));
}
