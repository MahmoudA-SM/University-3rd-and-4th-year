#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10

char* mallocString(unsigned int stringLength);

int main(int argc, char* argv[]){
	char* s;
	for(int i=0; i< argc; i++){
		// heap memory previously pointed to by s is about to be lost!
		s = mallocString(strlen(argv[i]) );
		if(s==(char*)NULL){
			fprintf(stderr, "Memory failure\n");
			return EXIT_FAILURE;
		}
		free(s);
		strcpy(s,argv[i]);
		printf("%s\n", s);
	}
	return EXIT_SUCCESS;
}//End main()
char* mallocString(unsigned int stringLength){
	return (char*)malloc( (stringLength+1) * sizeof(char));
}