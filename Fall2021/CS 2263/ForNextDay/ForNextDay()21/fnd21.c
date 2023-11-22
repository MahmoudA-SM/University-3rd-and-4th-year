#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    char c;
    struct link *next;
} Link;

Link *mallocLink(int n)
{
    Link *l = (Link *)malloc(sizeof(Link));
    if (l == (Link *)NULL)
    {
        printf("malloc error");
    }
    return l;
}

int main()
{
    char h = 'h';
    Link *pHead = mallocLink(sizeof(Link));
    Link* pHeap = mallocLink(sizeof(Link));

    pHead->c = h;
    pHead->next = pHeap;

    pHeap->c = 'i';
    pHeap->next = pHead;

    printf("%c", pHead->c);
    printf("%c\n", pHead->next->c);

    return EXIT_SUCCESS;
}