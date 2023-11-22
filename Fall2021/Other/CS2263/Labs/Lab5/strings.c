#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "Strings.h"

typedef char* String;

String getfc(FILE* pFIn, String terminators, int n);

int charInString(String t, char c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int stringsize)
{
    return (String)malloc(sizeof(char)*(stringsize + 1));
}


// just a cover function for free()
void freeString(String s)
{
    free(s);
}


// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s)
{
    int strSize = sizeof(s);
    String strCopy = mallocString(strSize);
    if(strCopy == (char*)NULL)
    {
        fprintf(stderr, "Failed to allocate memory\n");
    }
    strcpy(strCopy, s);
    return strCopy;
}


String* duplicateStringList(String* s, int n)
{
    String* slCopy;
    // Allocate the list
    slCopy = (String*)malloc(sizeof(String)*n);
    if(slCopy == (String*)NULL) return slCopy;

    // Allocate/duplicate the strings
    for(int i = 0; i < n; i++)
    {
        slCopy[i] = duplicateString(s[i]);
        if(slCopy[i] == (String)NULL)
        {
            // Bad stuff - clean up and return
            for(int j = 0; j < i; j++)
            {
                freeString(slCopy[j]);
            }
            free(slCopy);
            slCopy = (String*)NULL;
            break;
        }
    }
    return slCopy;
}

/*
// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (char*)NULL
String getfString(FILE* pFIn, String terminators)
{
    String s = getfc(pFIn, terminators, 0);
    return s;
}
*/

char* getString(char* terminators, int n)
{
    
    char* s;
    s = getfc(stdin, terminators, n);
    return s;
}

/*
String getfc(FILE* pFIn,String terminators, int n)
{

    String s;
    char c = fgetc(pFIn);
    //base case
    if(c == EOF || charInString(terminators, c))
    {
        // allocate a string
        s = mallocString(n);    
        if(s != (String)NULL)
        {
            // terminate the string
            s[n+1] = (char*)NULL;
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}
*/


/*
int charInString(String t, char c)
{
    int i = 0;
    while(t[i] != (char)NULL)
    {
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}
*/

int compareString(const void * arg1, const void * arg2)
{
    const char * ptr1 = (const char *)arg1;
    const char * ptr2 = (const char *)arg2;

    if(strcmp(ptr1, ptr2)<0)
    {
        return -1;
    }
    if (strcmp(ptr1, ptr2)==0)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    
}
//End