#include <stdlib.h>
#include <stdio.h>
int tagL(char *str)
{
	int i = 0;
	while (str[i] != '>' && str[i] != ' ')
	{
		i++;
	}
	return i;
}
void* getTag(char *s)
{
	int i = 0;
	while (s[i] != NULL)
	{
		if (s[i] == '<')
		{
			if (s[i + 1] != '!' && s[i + 1] != '/')
			{
				return &s[i + 1];
			}
		}
		i++;
	}
}
int isSingular(char *s, char *s1)
{
	int i = 0;
	int j = tagL(s);
	int k = tagL(s1);

	if (k == j)
	{
		while ((s[i] == s1[i]) && (i < j))
		{
			i++;
		}
		if (i != j)
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char *argv[])
{
	FILE *f = fopen(argv[1], "r");
	int *counter = (int *)malloc(sizeof(int) * 100);
	char *inputArray = (char *)malloc(sizeof(char) * 100000);
	char *inputArrayC = inputArray;
	char **inputArrayP = (char **)malloc(sizeof(char *) * 100);
	int inputArrayLength = 0;
	int numtags = 0;
	int i;
	char inputChar = fgetc(f);

	while (inputArrayLength < 100000 && inputChar != EOF)
	{
		inputArray[inputArrayLength] = inputChar;
		inputArrayLength++;
		inputChar = fgetc(f);
	}

	inputArrayC = getTag(inputArrayC);
	while (inputArrayC != (char *)NULL)
	{

		int bln = 1;
		i = 0;
		while (i < numtags)
		{
			if (*inputArrayC == *inputArrayP[i])
			{
				int unique = isSingular(inputArrayP[i], inputArrayC);
				if (unique == 0)
				{
					counter[i] += 1;
					bln = 0;
				}
			}
			i++;
		}
		if (bln == 1)
		{
			inputArrayP[numtags] = inputArrayC;
			counter[numtags] = 1;
			numtags++;
		}
		inputArrayC = getTag(inputArrayC);
	}
	i = 0;
	while(i < numtags)
	{
		display(counter[i], inputArrayP[i]);
		i++;
	}
	free(counter);
	free(inputArray);
	free(inputArrayP);
	return EXIT_SUCCESS;
}