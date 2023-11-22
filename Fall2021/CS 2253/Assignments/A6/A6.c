#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAX_LENGTH 50

char *find_blank(char *start)
{
    char *copy = start;
    while (*copy != (char)NULL)
    {
        if (*copy == ' ')
        {
            return copy;
        }
        copy++;
    }
    printf("There are no blanks\n");
    return (char *)NULL;
}

//----------------------------------1 DONE---------------------------------------------------------------------------------------

void four_stars(char *start)
{
    int i = 0;
    // char* startcopy = start;
    while (i < 4)
    {
        *(start + i) = '*';
        // startcopy++;
        i++;
    }
}

//----------------------------------2 DONE---------------------------------------------------------------------------------------

void censor(char *start)
{
    char *startcopy = start;
    do
    {
        start=find_blank(start);
        if ((start - startcopy == 4))
        {
            four_stars(startcopy);
        }
        start++;
        startcopy = start;
    } while (find_blank(start) != NULL);

    if (*(start + 4) == (char)NULL)
    {
        four_stars(startcopy);
    }
}

int main()
{
    // test 1

    char *test1 = "test one let's see how it goes.";

    printf("\n\nTest one: %s\n", test1);
    printf("Address of the first character of test 1 (Should be less than the next print statement by 4): %p\n", test1);
    printf("Address of the first blank of test 1: %p\n\n\n", find_blank(test1));

    // test 2

    char *test2 = " first char is the first blank.";

    printf("Test two: %s\n", test2);
    printf("Address of the first character of test 2 (Should match the next print): %p\n", test2);
    printf("Address of the first blank of test 2: %p\n\n\n", find_blank(test2));

    // test 3

    char *test3 = "lastcharistheblank ";

    printf("Test three: %s\n", test3);

    char *test3copy = test3;
    char *test3last = test3copy;

    while (*(test3last + 1) != (char)NULL)
    {
        test3last = test3copy;
        test3copy++;
        test3last++;
    }

    printf("Address of the last character of test 3 (Should match the next print): %p\n", test3last);
    printf("Address of the first blank of test 3: %p\n\n\n", find_blank(test3));

    // test 4

    char *test4 = "therearenoblanks";

    printf("Test four: %s\n", test4);
    if (find_blank(test4) != (char *)NULL)
    {
        printf("Address of the first blank of test 4: %p\n\n\n", find_blank(test4)); // should not print
    }

    printf("\n\n");

    //----------------------------------1 DONE---------------------------------------------------------------------------------------

    char *test5 = "Four stars";
    char *test5heap = (char *)malloc(sizeof(char) * 200);
    char *mover = test5heap;
    while (*test5 != (char)NULL)
    {
        *mover = *test5;
        mover++;
        test5++;
        if (*(test5 + 1) == NULL)
        {
            *(mover + 1) = NULL;
        }
    }

    printf("String before the 4 stars: %s\n\n\n", test5heap);

    four_stars(test5heap);
    printf("String after the 4 stars: %s\n\n\n", test5heap);

    free(test5heap);

    //----------------------------------2 DONE---------------------------------------------------------------------------------------

    char *test6 = "Final test should take notes.";
    char *test6heap = (char *)malloc(sizeof(char) * 200);
    char *mover2 = test5heap;
    while (*test6 != (char)NULL)
    {
        *mover2 = *test6;
        mover2++;
        test6++;
        if (*(test6 + 1) == NULL)
        {
            *(mover2 + 1) = NULL;
        }
    }

    printf("Test 6 before censoring: %s\n", test6heap);
    censor(test6heap);
    printf("Test 6 after censoring: %s\n", test6heap);
    printf("\n\n");
    return EXIT_SUCCESS;
}