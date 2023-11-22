#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    char* c;
    struct stat s;
    ssize_t nB, bS;
    int result;

    if (argc != 2) 
    {
        printf("usage: %s to get info on a file\n", argv[0]);
		exit(1);
    }
	result = lstat(argv[1], &s);

    if (result == -1) 
    {
		perror("error performing stat on file");
		exit(1);
    }

           

    bS = s.st_size + 1;

    c = malloc(bS);
    
    nB = readlink(argv[1], c, bS);
    
    if (nB == -1) 
    {
        perror("readlink");
        exit(1);
    }

         
    printf("'%s' link points to '%.*s file'\n", argv[1], (int) nB, c);

    free(c);
    exit(EXIT_SUCCESS);
}