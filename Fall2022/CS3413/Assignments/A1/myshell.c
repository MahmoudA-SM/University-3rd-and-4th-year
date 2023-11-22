#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFSIZE 81
#define CWDMAX 100

int main(int argc, char*argv[])
{
    char* cmd;
    char buffer [80];
    int length, return_code, processid;
    int fileDescriptor[2]; // 0 read | 1 write
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






        //Commands Tokenizer
        char* cmdList[CWDMAX];
        char* token2;
        char* cmdCopy2 = cmd;
        int k = 0;
        while (token2 = strtok_r(cmdCopy2, "|", &cmdCopy2))
        {
            cmdList[k] = token2;
            printf("token2: %s\n", token2);


            char* argList[CWDMAX];
            char* token;
            char* cmdCopy = cmdList[k];
            int i = 0;
            while((token = strtok_r(cmdCopy, " ", &cmdCopy))){
                printf("Token: %s\n", token);
                int j =0;
                
                argList[i] = token;

                if(strcmp(token,"exit") == 0){
    
                    
                    exit(0);

                }
                else if (strcmp(token, "cd") == 0)
                {
                    if(cmdCopy != NULL){
                        printf("CMDCOPY: %s\n", cmdCopy);
                        chdir(cmdCopy);
                        // printf("CD in cd speciallized");
                        }
                }
                i++;
            }
            k++;
        }





        // char* argList[50];
        // char* token;
        // char* cmdCopy = cmd;
        // int i = 0;
        // while((token = strtok_r(cmdCopy, " ", &cmdCopy))){
        //     printf("Token: %s\n", token);
        //     int j =0;
            
        //     argList[i] = token;

        //     if(strcmp(token,"exit") == 0){
 
                
        //         exit(0);

        //     }
        //     else if (strcmp(token, "cd") == 0)
        //     {
        //         if(cmdCopy != NULL){
        //             printf("CMDCOPY: %s\n", cmdCopy);
        //             chdir(cmdCopy);
        //             // printf("CD in cd speciallized");
        //             }
        //     }
        //     i++;
        // }

        
        

        pipe(fileDescriptor);
        processid = fork();

        //parent
        // if(processid != 0)
        // {
        //     close(fileDescriptor[1]);
        //     int ret;
        //     wait(NULL);
        //     // dup2(fileDescriptor[0], stdout);
        //     // printf("y piped: %d\n", ret);
        // }
        // //child
        // else
        // {
        //     argList[i] = NULL;

        //     close(fileDescriptor[0]);

        //     if(strcmp(argList[0],"cd")!= 0 && strcmp(argList[0],"exit")!= 0){
        //         //printf("1Return code in child: %d\n", return_code);

        //         return_code = execvp(cmd, argList);
        //         // printf("Cd in retcode");
        //         // dup2(execvp(cmd, argList) ,fileDescriptor[1]);
        //         if(return_code != 0)
        //         {
        //             printf("Error executing %s.\n", cmd);
        //             exit(0);
        //         }
        //     }
        //     if(strcmp(argList[0],"cd") == 0){
        //         exit(0);
        //     }
        //     // return_code = execvp(cmd, argList);
        //     // if(return_code != 0)
        //     // {
        //     //     printf("Error executing %s.\n", cmd);
        //     //     exit(0);
        //     // }
        //     // exit(0);
            
        // }
        // if(getcwd(cwd, sizeof(cwd))!=NULL){
        // printf("%s%c ", cwd, '%');
        // }
        cmd = fgets(buffer, BUFSIZE, stdin);
        
        
    }

    








    return EXIT_SUCCESS;
}