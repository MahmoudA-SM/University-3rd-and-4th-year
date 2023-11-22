#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

char tags[100][10]; 
static int array[100]; 
char storing[100000]; 
char tempArr[100][10]; 

int counter = 0; 
int variable = 0; 
int anotherVar = 0;


void display()
{    
    for(int i = 0; i < counter; i++)
    {        
        printf("%s found: %d\n", *(tags+i), array[i]);    
    }
}


int checking(char* var)
{    
    if((*var) == '\0')
    {        
        return -5;    
    }    
    
    if(counter == 0)
    {        
        return -1;   
    }    
    
    else
    {        
        for(int i = 0; i < counter; i++)
        {            
            int result = strcmp(*(tags+i), var);            
            
            if(result == 0)
            {                
                return i;            
            }        
        }        
        return -1;    
    }
}


void finding(char* charac)
{    
    int a = 0;    
    int len = strlen(charac);    
    
    for(int i = 0; i < len; i++)
    {        
        if(charac[i] == '<')
        {            
            for(int j = i+1; j < len; j++)
            {                
                if(charac[j] == '>'|| charac[j] == ' '|| charac[j] == '/' || charac[j] == '\n')
                {                    
                    i = j;                    
                    break;                
                }                
                
                else
                {                    
                    tempArr[anotherVar][a] = charac[j];                    
                    a++;                
                }            
            }            
            
            char* var1 = &tempArr[anotherVar][0];            
            int ans = checking(var1);            
            
            if(ans == -1)
            {                
                for(int k = 0; k < strlen(var1); k++)
                {                    
                    tags[variable][k] = tempArr[anotherVar][k];                
                }                
                array[variable] = array[variable] + 1;                
                variable++;                
                counter++;            
            }           
            
            else
            {                
                array[ans] = array[ans] + 1;            
            }            
            anotherVar++;            
            a = 0;        
        }    
    } 
}


int main(int argc, char ** argv)
{    
    char* inputtt = &storing[0];
    scanf("%*c", inputtt);    
    finding(inputtt);    
    display(); 
}