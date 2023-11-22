#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

char tagStore[100][10]; 
static int arr[100]; 
char storeInput[100000]; 
char tempArr[100][10]; 

int countTagStore = 0; 
int variable1 = 0; 
int b = 0;


int checkValue(char* var1)
{    
    if((*var1) == '\0')
    {        
        return -5;   
    }  

    if(countTagStore == 0)
    {        
        return -1;    
    }    
    else
    {        
        for(int i = 0; i < countTagStore; i++)
        {            
            int a1 = strcmp(*(tagStore+i),var1);            
            if(a1 == 0)
            {                
                return i;            
            }        
        }        
        return -1;    
    }
}


void display()
{    
    for(int i = 0; i < countTagStore; i++)
    {        
        printf("%s - %d\n",*(tagStore+i),arr[i]);    
    }
}


void find(char* in)
{    
    int a = 0;    
    int var = strlen(in);   

    for(int i = 0; i < var; i++)
    {        
        if(in[i] == '<')
        {            
            for(int j = i+1; j < var; j++)
            {                
                if(in[j] == '>'||in[j] == ' '||in[j] == '/' || in[j] == '\n')
                {                    
                    i = j;                    
                    break;                
                }    

                else
                {                    
                    tempArr[b][a] = in[j];                    
                    a++;                
                }            
                            
                char* t1 = &tempArr[b][0];            
                int a2 = checkValue(t1); 

                if(a2 == -1)
                {                
                    for(int k = 0; k < strlen(t1); k++)
                    {                    
                        tagStore[variable1][k] = tempArr[b][k];                
                    } 

                    arr[variable1] = arr[variable1] + 1;                
                    variable1++;                
                    countTagStore++;            
                }     

                else
                {                
                    arr[a2] = arr[a2] + 1;            
                }  

                b++;            
                a = 0;        
            }    
        } 
    }

}
int main(int argc, char ** argv)
{    
    char* input1 = &storeInput[0];
    scanf("%[^\t]%*c", input1);    
    find(input1);    
    display(); 
}

/*
int main(int argc, char ** argv)
{    
    char *buffer = NULL;    
    size_t size = 0;    
    FILE *fp = fopen("C:\\Users\\srivk\\OneDrive\\Desktop\\UNB\\Summer2020\\CS2263\\Assignments\\Assignment3\\A3Data\\HelloWorld.html", "r");    
    fseek(fp, 0, SEEK_END);    
    rewind(fp);    
    buffer = malloc((size + 1) * sizeof(*buffer));    
    fread(buffer, size, 1, fp);    
    buffer[size] = '\0';    
    find(buffer);    
    display();    
    return 0; 
}
*/