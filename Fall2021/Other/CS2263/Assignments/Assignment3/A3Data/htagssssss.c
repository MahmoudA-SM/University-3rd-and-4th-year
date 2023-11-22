#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAG_SIZE 10

char tag[100][10];
char arr[100][10];
char arr1 [100000];

int count = 0;
int countTag = 0;
int var = 0;
int var1 = 0;
int var3 = 100;
static int var4[100]; 

void tagSearch(char* namingIsHard);
void storing(int num, char* anotherVar);
void display();



int main(int argc, char * * argv)
{
    FILE *fptr;

    char* variable;
    double variable1;

    //char* fname = argv[1];

    //fptr = fopen("C:\\Users\\srivk\\OneDrive\\Desktop\\UNB\\Summer2020\\CS2263\\Assignments\\Assignment3\\A3Data\\HelloWorld.html", "r"); //fill in the file name or whatever

    fptr = fopen(argv[1], "r");

    if(fptr != NULL)
    {
        printf("ERROR!\n");
        return EXIT_FAILURE;
    }

    fseek(fptr, 0L, SEEK_END);

    variable1 = ftell(fptr);

    variable = calloc(1, variable1+1);

    if(!variable)
    {
        fclose(fptr);
       // fputs("Failed to allocate memory\n", stderr);
       printf("Failed to allocate memory\n");
       exit(1);
    }

    printf("Hey1\n");
   // if(1 != fread(variable, variable1, 10, fptr))
    if(scanf("%c", &variable) == 0)
    {
        //fclose(fptr),
        //free(variable),
        //fputs("Could not read\n", stderr),
        printf("Could not read\n");
        return EXIT_FAILURE;
    }

    printf("Hey12\n");
    tagSearch(variable);
    display();
}


void storing(int num, char* anotherVar)
{
    if(num == -1)
    {
        int digit = 0;
        
        while(digit < strlen(anotherVar))
        {
            tag[var3][digit] = arr[countTag][digit];
            digit++;
        }

        var4[var3] = var4[var3]+1;

        var3++;
        count++;
    }

    else
    {
        var4[num] = var4[num]+1;
    }
}


void tagSearch(char* namingIsHard)
{
    int a, b = 0;
    int c;
    c = strlen(namingIsHard);

    while(b < c)
    {
        if(namingIsHard[b] == '<')
        {
            int i1;
            for(i1 = b+1; i1 < c; i1++)
            {
                if(namingIsHard[i1] == '>' || namingIsHard[i1] == ' ' || namingIsHard[i1] == '/')
                {
                    b = i1;

                    goto check;
                }
                else
                {
                    arr[countTag][a] = namingIsHard[i1];
                    a++;
                }
            }

            check: ;
            char* taggg = &arr[countTag][0];
            int d = 0;

            if((*taggg) == '\0')
            {
                d = -55; 

                goto check1;
            }

            if(count == 0)
            {
                d = -1;

                goto check1;
            }
            else
            {
                int e = 0;
                while(e < count)
                {
                    int g;
                    g = strcmp(*(tag+e), taggg);

                    if(g == 0)
                    {
                        d = e;

                        goto check1;
                    }
                    e++;
                }

                d = -1;
                
                goto check1;
            }

            check1: ;
            storing(d, taggg);
            countTag++;
            a = 0;
        }

        b++;
    }
}

void display()
{
    int num1 = 0;

    while(num1 < count)
    {
        printf("%c found: \t%d\n", *(tag+num1), var4[num1]);
        num1++;
    }
}












