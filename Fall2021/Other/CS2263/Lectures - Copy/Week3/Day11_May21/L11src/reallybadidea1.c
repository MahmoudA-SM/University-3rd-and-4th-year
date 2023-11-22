#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10

int main(int argc, char* argv[]){

	char* s = (char*)malloc(sizeof(char)*(MAXLEN+1) );
	// stuff here
	while(*s != (char)NULL){
		printf("%c", *s);
		s++;
	}
	printf("\n");
	// So where is the beginning of the string held?
	return EXIT_SUCCESS;
}
