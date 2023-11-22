#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFSIZE 81
int main (int argc, char* argv[])
{
    char* cmd;
    char buffer [80];
    int length, return_code, processid;
  
    printf("Enter a command: > ");
    cmd = fgets(buffer, BUFSIZE, stdin);
    
    while(cmd != NULL)
    {
        length = strlen(buffer);
        if(buffer[length-1] == '\n'){
        buffer[length-1] = '\0';
    }
        processid = fork();
        if(processid != 0)
        {
            wait(NULL);
        }
        else
        {
            return_code = execlp(cmd,cmd, NULL);
            if(return_code != 0)
            {
                printf("Error executing %s.\n", cmd);
                exit(0);
            }
        }
        printf("Enter a command: > ");
        cmd = fgets(buffer, BUFSIZE, stdin);
    }

    return EXIT_SUCCESS;
}