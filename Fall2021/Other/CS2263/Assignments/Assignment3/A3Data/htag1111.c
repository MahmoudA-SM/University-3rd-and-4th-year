#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
char base[100][10]; 
char realtags[100][10]; 
int tagcnt = 0; 
int counter = 0; 
int notwhatithink = 0; 
static int nothiddnetimes[100]; 
int H = 100; char html[20000]; 
void tags(char* htm); 
void store(int val,char* tt); 
void Display(); 

/* main method is just used to take input from the user and then call multiple methods to check tags and finally call the display function */ 
int main (int argc, char *argv[]) 
{ 
    FILE *fptr; 
    long sz; 
    char *b; 
    fptr = fopen ( "/home1/ugrads/ypandya/cs2263/test.html" , "rb" );
    if( !fptr ) 
    perror("/home1/ugrads/ypandya/cs2263/test.html"),exit(1); 
    fseek( fptr , 0L , SEEK_END); 
    sz = ftell( fptr ); 
    rewind( fptr ); 
    b = calloc( 1, sz+1 ); 
    
    if( !b ) 
    fclose(fptr),fputs("memory alloc fails",stderr),exit(1); 
    
    if( 1!=fread( b ,sz, 1 , fptr) ) fclose(fptr),free(b),fputs("entire read fails",stderr),exit(1); 
    
    tags(b); 
    Display(); 
}


/* This store function will store the values in the main tag array and keep track of the number of times each tag occurs */
void store(int val, char* tt) 
{ 
    if(val == -1) 
    { 
        int looper3 = 0; 
        
        while(looper3 < strlen(tt)) 
        { 
            realtags[notwhatithink][looper3] = base[tagcnt][looper3]; 
            looper3++; 
        } 
        
        nothiddnetimes[notwhatithink] = nothiddnetimes[notwhatithink] +1;
        notwhatithink++; counter++; 
    } 
    else if(val == -69) 
    {

    } 
    
    else 
    { 
        nothiddnetimes[val] = nothiddnetimes[val] + 1;
    } 
    
    int c; 
    for(c=0; c<100;c++) 
    { 
        if(nothiddnetimes[c] > 20) 
        {
        }
    }

}
/* This display function will just print the values we are instructed to show for output */
void Display() 
{ 
    int finallooop = 0; 
    while(finallooop < counter) 
    { 
        printf("%s tag found %d times.\n",*(realtags+finallooop),nothiddnetimes[finallooop]); 
        finallooop++; 
    }
}
