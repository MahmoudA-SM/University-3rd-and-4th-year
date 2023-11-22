#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isTag(char* first)
{

	while(*first !='>')
  {
		if(*first == '!'|| *first == '/' || *first == '=')
    {
			return 0;
		}
		first++;
	}
	return 1;
} 

bool isIdentical(char* input, char* array)
{
	while(*input != '>')
  {
		if(*(input+1) != *array)
    {
			return false;
		}
		input++;
		array++;
	}
	return true;
	
}

int main(int argc, char* argv[])
{
	char inputArray[100000]; //stores the text
	char* inputArrayp = inputArray;
	
	char* adressesP[100];
	int occurunces[100];
	char charInput = fgetc(stdin);

	while(charInput != EOF)
  {
		*inputArrayp = charInput;
		inputArrayp++;
		charInput = fgetc(stdin);
	}
	*inputArrayp = EOF;
	
	inputArrayp = inputArray;
	char** cArray = adressesP;
	int* iArray = occurunces;
	while(*inputArrayp != EOF)
  {
		cArray = adressesP;
		iArray = occurunces;
		if(*inputArrayp == '<' && isTag(inputArrayp) == 1)
    {
			if(*cArray == NULL)
      {
				*cArray = inputArrayp+1;
				*iArray = 1;
				cArray++;
				iArray++;
			}
			else
      {
				bool same=false;
				while(*cArray != NULL && !same)
        {
					same = isIdentical(inputArrayp, *cArray);
					iArray++;
					*cArray++;
				}
				if(same)
        {
					*(iArray-1) +=1;
				}
				else
        {
					*cArray = inputArrayp+1;
					*iArray = 1;
					cArray++;
					iArray++;
				}
			}
				
		}
		else if(*inputArrayp=='!')
    {
			inputArrayp++;
			inputArrayp++;
			while(*inputArrayp !='-')
      {
				inputArrayp++;
			}
		}
		inputArrayp++;
	}
	
	cArray = adressesP;
	iArray = occurunces;
	
	while(*cArray != NULL)
  {
		int k=0;
		while(*((*cArray)+k) != '>')
    {
			printf("%c", *((*cArray)+k));
			k++;
		}
		printf("\t\t%d\n", *iArray);
		iArray++;
		cArray++;
	}
	
	return EXIT_SUCCESS;
}