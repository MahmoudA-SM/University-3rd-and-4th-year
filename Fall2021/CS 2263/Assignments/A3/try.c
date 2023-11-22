//htags.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCHAR 100000
#define MAXTAG 100
int tagCheck(char* start);
bool isSame(char* input, char* array);

int main(int argc, char* argv[]){
	char inputArray[MAXCHAR];
	char* inputArrayP = inputArray;
	
	char* tagArray[MAXTAG];
	int occurancesArray[MAXTAG];
	char inputChar = fgetc(stdin);

	while(inputChar != EOF){
		*inputArrayP = inputChar;
		inputArrayP++;
		inputChar = fgetc(stdin);
	}
	*inputArrayP = EOF;
	
	inputArrayP = inputArray;
	char** cArray = tagArray;
	int* iArray = occurancesArray;
	while(*inputArrayP != EOF){
		cArray = tagArray;
		iArray = occurancesArray;
		if(*inputArrayP == '<' && tagCheck(inputArrayP) == 1){
			if(*cArray == NULL){
				*cArray = inputArrayP+1;
				*iArray = 1;
				cArray++;
				iArray++;
			}
			else{
				bool same=false;
				while(*cArray != NULL && !same){
					same = isSame(inputArrayP, *cArray);
					iArray++;
					*cArray++;
				}
				if(same){
					*(iArray-1) +=1;
				}
				else{
					*cArray = inputArrayP+1;
					*iArray = 1;
					cArray++;
					iArray++;
				}
			}
				
		}
		inputArrayP++;
	}
	
	cArray = tagArray;
	iArray = occurancesArray;
	
	while(*cArray != NULL){
		int k=0;
		while(*((*cArray)+k) != '>'){
			printf("%c", *((*cArray)+k));
			k++;
		}
		printf("\t\t%d\n", *iArray);
		iArray++;
		cArray++;
	}
	
	return EXIT_SUCCESS;
}

int tagCheck(char* start){ //return 1 if it is considered as tag 0 if not

	while(*start !='>'){
		if(*start == '=' || *start == '!'|| *start == '/'){
			return 0;
		}
		start++;
	}
	return 1;
} 

bool isSame(char* input, char* array){
	while(*input != '>'){
		if(*(input+1) != *array){
			return false;
		}
		input++;
		array++;
	}
	return true;
	
}