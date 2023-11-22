#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRINGS_H
#define STRINGS_H
typedef char *String;
// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int stringsize);

// just a cover function for free()
void freeString(String s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s);
String *duplicateStringList(int i, String *sl);
int compareStrings(void *s1, void *s2);
String getString();
#endif