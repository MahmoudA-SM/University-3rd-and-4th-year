#ifndef STRINGS_H
#define STRINGS_H
typedef char* String;
String mallocString(int stringsize);

void freeString(String s);

String duplicateString(String s);

int compareStrings(const void * arg1, const void * arg2);

char** duplicateStringList(int n, char** sl);

void freeStringList(int n, char** s);

int fputString(FILE* pFOut, String s);

String fgetString(FILE* pFIn);

String getfString(FILE* pFIn, String terminators);

String getString(String terminators);
#endif