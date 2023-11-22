#ifndef STRINGS_H
#define STRINGS_H
typedef char* String;
typedef String* StringList;
// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int stringsize);

String getfString(FILE* pFIn, String terminators);
String getString(String terminators);

#endif