#include <stdio.h>

void merge(int curArray[], int l, int m1,

           int m2, int h, int destArray[])

{

    int i = l, j = m1, k = m2, lc = l;

    while ((i < m1) && (j < m2) && (k < h))

    {

        if (curArray[i] < curArray[j])

        {

            if (curArray[i] < curArray[k])

            {

                destArray[lc++] = curArray[i++];
            }

            else

            {

                destArray[lc++] = curArray[k++];
            }
        }

        else

        {

            if (curArray[j] < curArray[k])

            {

                destArray[lc++] = curArray[j++];
            }

            else

            {

                destArray[lc++] = curArray[k++];
            }
        }
    }

    while ((i < m1) && (j < m2))

    {

        if (curArray[i] < curArray[j])

        {

            destArray[lc++] = curArray[i++];
        }

        else

        {

            destArray[lc++] = curArray[j++];
        }
    }

    while ((j < m2) && (k < h))

    {

        if (curArray[j] < curArray[k])

        {

            destArray[lc++] = curArray[j++];
        }

        else

        {

            destArray[lc++] = curArray[k++];
        }
    }

    while ((i < m1) && (k < h))

    {

        if (curArray[i] < curArray[k])

        {

            destArray[lc++] = curArray[i++];
        }

        else

        {

            destArray[lc++] = curArray[k++];
        }
    }

    while (i < m1)

        destArray[lc++] = curArray[i++];

    while (j < m2)

        destArray[lc++] = curArray[j++];

    while (k < h)

        destArray[lc++] = curArray[k++];
}

void MS3WR(int curArray[], int l,

                      int h, int destArray[])

{
    int m1, m2;

    if (h - l < 2)

        return;

    m1 = l + ((h - l) / 3);

    m2 = l + 2 * ((h - l) / 3) + 1;

    MS3WR(destArray, l, m1, curArray);

    MS3WR(destArray, m1, m2, curArray);

    MS3WR(destArray, m2, h, curArray);

    merge(destArray, l, m1, m2, h, curArray);
}

void MS3Way(int curArray[], int n)

{

    int i;

    if (n == 0)

        return;

    int fArray[n];

    for (i = 0; i < n; i++)

        fArray[i] = curArray[i];

    MS3WR(fArray, 0, n, curArray);

    for (int i = 0; i < n; i++)

        curArray[i] = fArray[i];
}

int main()

{

    int data[1000], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        scanf("%d", &data[i]);
    }

    MS3Way(data, n);

    printf(" 3 way merge sort: \n");

    for (i = 0; i < n; i++)

    {

        printf("%d ", data[i]);
    }

    return 0;
}
