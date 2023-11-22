typedef char* String;

String getfc(FILE* pFIn, String terminators, int n);

String mallocString(int stringsize)
{
    return (String)malloc(sizeof(char)*(stringsize + 1));
}


void freeString(String s)
{
    free(s);
}


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


char* getString(char* terminators, int n)
{
    char* s;
    //s = getfc(stdin, terminators, n);
    return s;
}


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