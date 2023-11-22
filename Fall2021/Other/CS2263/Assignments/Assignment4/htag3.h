#define TOTAL_TAGS 100
void tagCounter(char *charac, char **tagArr, int *counter)
{
    int i = 0;
    int tag = 0;

    for(i = 0; i < TOTAL_TAGS; i++)
    {
        if(tagArr[i] == NULL)
        {
            break;
        }
        else if(strncmp(charac, tagArr[i], strlen(charac)) == 0)
        {
            tag = 1;
            break;
        }
    }

    if (tag)
    {
        counter[i] = counter[i]+1;
    }
    else
    {
        tagArr[i] = charac;
        counter[i] = 1;
    }
}