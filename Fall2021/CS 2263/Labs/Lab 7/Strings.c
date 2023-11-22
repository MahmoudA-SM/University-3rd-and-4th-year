//Strings.c
#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

typedef char* String;

String mallocString(int stringsize){
	String s = (String)malloc(sizeof(char) * (stringsize+1));
	if(s == (String)NULL){
		return (String)NULL;
	}
	return s;
}

void freeString(String s){
	free(s);
}

String duplicateString(String s){
	int length = strlen(s);
	
	String str = mallocString(length);
	if(str == (String)NULL){
		return (String)NULL;
	}
	
	strcpy(str, s);
	return str;
}

int compareStrings(const void* arg1, const void* arg2){
    const char* str1 = (const char*) arg1;
    const char* str2 = (const char*) arg2;
	
    int length1 = strlen(str1);
    int length2 = strlen(str2);
	int length = 0;
	
    if(length1 < length2){
         length = length1;
    }
	else{
		length = length2;
	}
	
	for(int i=0; i<length; i++){
		if(str1[i] != str2[i]){
			return str1[i]-str2[i];
		}
	}
	return 0;
}

char** duplicateStringList(int n, char** sl) {
	char** stringList;
	int i;
	int j;

	// allocate an array of pointers to strings (each string is a char*)
	stringList = (char**) malloc(sizeof(char*) * n);
	if(stringList == (char**)NULL){
		fprintf(stderr,"Memory failure, terminating");
			return (char**)NULL;
	}
	for(i=0; i<n; i++){
		// allocate the string
		stringList[i] = duplicateString(sl[i]);
		if(stringList[i] == (char*)NULL){
			fprintf(stderr,"Memory failure, terminating");
			// Clean up allocated memory to-date
			for(j=0; j<i; i++){
				free(stringList[j]);
			}
			free(stringList);
			return (char**)NULL;
		}
	}
	return stringList;
}

void freeStringList(int n, char** s){
	int j;
	for(j=0; j<n; j++){
		free(s[j]);
	}
	free(s);
}

int fputString(FILE* pFOut, String s){
	int length = strlen(s);
	
	fprintf(pFOut, "%d ", length);
	int i;
	for(i=0; i<length; i++){
		fputc(s[i], pFOut);
	}
	
	return length;
}

String fgetString(FILE* pFIn){
	int length;
	fscanf(pFIn, "%d", &length);
	fgetc(pFIn);
	
	String s = mallocString(length);
	int i;
	
	for(i=0; i<length; i++){
		s[i] = fgetc(pFIn);
	}
	
	return s;
}

int charInString(String t, char c){
    int i = 0;
    while(t[i] != (char)NULL){
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}

String getfc(FILE* pFIn, String terminators, int n){

    String s;
    char c = fgetc(pFIn);
    //base case
    if(c == EOF || charInString(terminators, c)){
        // allocate a string
        s = mallocString(n);    
        if(s != (String)NULL){
            // terminate the string
            s[n+1] = (char)NULL;
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}

String getfString(FILE* pFIn, String terminators){
    String s = getfc(pFIn, terminators, 0);
    return s;
}

String getString(String terminators){
    String s;
    s = getfc(stdin, terminators, 0);
    return s;
}