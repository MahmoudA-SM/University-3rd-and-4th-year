#include<stdio.h>

#include<string.h>

int main(int argc, char** argv)

{

    FILE *fptr ;

    char st[10]="";

    char ar[100][10]; // Array of strings which will store names of tags

    int ari[100]; // Array of integer to store number of occerences of corresponding tags

    for (int i=0;i<100;i++) ari[i]=0;

    int n=0;

    char* fname=argv[1]; // Getting name of input file as input from argumnets

    fptr = fopen(fname,"r"); // Reading the file

    if (fptr != NULL)

    {

        while(!feof(fptr)) // Checking if all content of file is analyzed or not. We will always check for this after getting character

            {

                char c = fgetc(fptr); // fgetc() to read file character wise

                if (c=='<' && !feof(fptr)) // Checking if some tag is starting from next character or not

                    {

                        char c2=fgetc(fptr);

                        if (c2!='/') // Filtering those which start with '/'

                            {

                                int i=0;

                                strcpy(st,""); // setting 'st' as blank string and we will store the name of tag in 'st'

                                while(c2!=10 && c2 != '>' && c2 != ' ' && !feof(fptr)) // Checking if name of tag is completely stored in 'st' or not

                                    {

                                        st[i]=c2; // Adding next character of the tag in 'st'

                                        c2=fgetc(fptr);

                                        i++;

                                    }

                                    st[i]='\0'; // Adding '\0' at the end because we are using the same variable 'st' everytime to store the tag name. If we get a tag smaller in size than previous one then '\0' will be on greater index than expected.

                                    int sw=1;

                                    for (int i=0 ; i<n ; i++) // Checking if the same tag was previously found or not

                                    {

                                        if (strcmp(ar[i],st)==0) // If yes

                                            {

                                                ari[i]++; sw=0; break; // Then we will increase it's count by 1

                                            }

                                    }

                                    if (sw==1) // Else

                                    {

                                        strcpy(ar[n],st); // We will add a new element in array of tags

                                        ari[n]++;

                                        n++; // and make it's count as 1

                                    }

                                }

                            }

                        }

                        for(int i=0;i<n;i++)

                        {

                            printf("%s %d \n",ar[i],ari[i]);

                        }

                    }

                }