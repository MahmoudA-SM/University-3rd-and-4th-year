#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFSIZE 81
#define CWDSIZE 256
#define MAXPARA 100

int main(int argc, char *argv[])
{
    char *cmd;
    int len;
    char buffer[BUFSIZE]; // room for 80 chars plus \0
    int pid;
    int ret_code;
    char cwd[CWDSIZE];
    int prevFD;

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s%c", cwd, '%');
    }

    cmd = fgets(buffer, BUFSIZE, stdin);
    while (cmd != NULL)
    {
        len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        char *token2;
        char *commandList[MAXPARA];
        char *rest2 = cmd;
        int c2 = 0;
        while ((token2 = strtok_r(rest2, "|", &rest2)))
        {
            commandList[c2] = token2;
            c2++;
        }

        int fd[c2-1][2];
        int i;
        for (i = 0; i < c2; i++)
        {
            pipe(fd[i]);

            char *token;
            char *argumentList[c2][MAXPARA];
            char *rest = commandList[i];
            int c = 0;
            while ((token = strtok_r(rest, " ", &rest)))
            {
                argumentList[i][c] = token;
                if (token != NULL)
                {
                    if (strcmp(token, "exit") == 0)
                    {
                        exit(0);
                    }
                    if (strcmp(token, "cd") == 0)
                    {
                        if (rest != NULL)
                        {
                            char *path = strcat(rest, "\0");
                            chdir(path);
                        }
                    }
                }
                c++;
            }

            pid = fork();
            if (pid != 0)
            { // parent
                wait(NULL);
                // close(fd[i][1]);
                
            }
            else
            { // child
                if (strcmp(argumentList[i][0], "cd") != 0)
                {
                    if(i<c2-1){
                        dup2(fd[i][1], STDOUT_FILENO);
                    }

                    ret_code = execvp(commandList[i], argumentList[i]);

                    if (ret_code != 0)
                    {
                        printf("Error executing command : %s\n", argumentList[i][0]);
                        exit(0);
                    }
                }
                else
                {
                    exit(0);
                }
            }
        }

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s%c", cwd, '%');
        }
        cmd = fgets(buffer, BUFSIZE, stdin);
    }
    return EXIT_SUCCESS;
}