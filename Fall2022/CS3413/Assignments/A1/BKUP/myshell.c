#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFSIZE 81
#define CWDMAX 81
int main(int argc, char*argv[])
{
    char* cmd;
    char buffer [80];
    int length, return_code, processid;
    char cwd[CWDMAX];
    if(getcwd(cwd, sizeof(cwd))!=NULL){
        printf("%s%c ", cwd, '%');
    }
    int x = 0;
    cmd = fgets(buffer, BUFSIZE, stdin);
    
    while(cmd != NULL)
    {
        length = strlen(buffer);
        if(buffer[length-1] == '\n'){
        buffer[length-1] = '\0';
        }

        char* argList[9];

        char* token;
        char* cmdCopy = cmd;
        int i = 0;

        while((token = strtok_r(cmdCopy, " ", &cmdCopy))){
            printf("Token: %s\n", token);
            argList[i] = token;
            if(strcmp(token,"exit") == 0){
                while (processid != 0)
                {
                    exit(0);
                }
                
                exit(0);
                // printf("EXit: \n");

            }
            else if (strcmp(token, "cd") == 0)
            {
                if(cmdCopy != NULL){
                    printf("CMDCOPY: %s\n", cmdCopy);
                    chdir(cmdCopy);
                }
            }
            i++;
        }
        // if (x==0){
        processid = fork();
        // }
        x++;
        if(processid != 0)
        {
            wait(NULL);
        }
        else
        {
            argList[i] = NULL;
        if(strcmp(argList[0],"cd")!= 0 && strcmp(argList[0],"exit")!= 0){
            return_code = execvp(cmd, argList);
            if(return_code != 0)
            {
                printf("Error executing %s.\n", cmd);
                // exit(0);
            }
        }
            // return_code = execvp(cmd, argList);
            // if(return_code != 0)
            // {
            //     printf("Error executing %s.\n", cmd);
            //     exit(0);
            // }
            exit(0);
            
        }
        if(getcwd(cwd, sizeof(cwd))!=NULL){
        printf("%s%c ", cwd, '%');
        }
        cmd = fgets(buffer, BUFSIZE, stdin);
        
        
    }

    








    return EXIT_SUCCESS;
}