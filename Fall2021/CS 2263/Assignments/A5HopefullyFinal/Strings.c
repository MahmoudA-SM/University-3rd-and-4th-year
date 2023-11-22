//Strings.c
#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

typedef char* String;
typedef String* StringList;

String mallocString(int stringsize){
	String s = (String)malloc(sizeof(char) * (stringsize+1));
	if(s == (String)NULL){
		return (String)NULL;
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
            s[n] = (char)NULL;
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