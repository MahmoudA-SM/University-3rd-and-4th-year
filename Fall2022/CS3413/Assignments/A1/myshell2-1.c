#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFSIZE 81
#define CWDMAX 100

int main(int argc, char *argv[])
{
    char *cmd;
    char buffer[80];
    int length, return_code, processid;
    char cwd[CWDMAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s%c ", cwd, '%');
    }

    cmd = fgets(buffer, BUFSIZE, stdin);

    while (cmd != NULL)
    {

        length = strlen(buffer);
        if (buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        // Commands Tokenizer
        char *cmdList[CWDMAX];
        char *token2;
        char *cmdCopy2 = cmd;
        int k = 0;

        while (token2 = strtok_r(cmdCopy2, "|", &cmdCopy2))
        {
            cmdList[k] = token2;
            printf("Command: %s\n", token2);
            k++;
        }
        // End of Commands Tokenizer

        int i = 0;
        int fileDescriptor[k - 1][2]; // 0 read | 1 write

        while (i < k)
        {

            // Start of Single Command Tokenizer
            char *argList[k][CWDMAX];
            char *token;
            int j = 0;
            char *cmdCopy = cmdList[i];

            while ((token = strtok_r(cmdCopy, " ", &cmdCopy)))
            {

                // char *cmdCopy = cmdList[i];
                printf("%d\n", j);
                printf("Token: %s\n", token);

                argList[i][j] = token;

                if (strcmp(token, "exit") == 0)
                {
                    exit(0);
                }
                else if (strcmp(token, "cd") == 0)
                {
                    if (cmdCopy != NULL)
                    {
                        printf("CMDCOPY: %s\n", cmdCopy);
                        chdir(cmdCopy);
                    }
                }
                j++;
            }

            processid = fork();
            // parent
            if (processid != 0)
            {
                // pipe(fileDescriptor);

                // close(fileDescriptor[1]);
                // int ret;
                wait(NULL);
                // dup2(fileDescriptor[0], ret);
                // printf("ret piped: %d\n", ret);
            }
            // child
            else
            {
                // argList[i] = NULL;
                printf("Command in child: %s\n", token2);
                // close(fileDescriptor[0]);
                if (strcmp(argList[0], "cd") != 0 && strcmp(argList[0], "exit") != 0)
                {
                    if (k - 1 > i)
                        dup2(fd[i][1], STDOUT_FILENO);

                    return_code = execvp(cmdList[k], argList[k]);
                    // dup2(return_code, fileDescriptor[1]);
                    if (return_code != 0)
                    {
                        printf("Error executing %s.\n", argList[i][0]);
                        exit(0);
                    }
                }
                if (strcmp(argList[0], "cd") == 0)
                {
                    exit(0);
                }
            }
            i++;
        }

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            getcwd(cwd, sizeof(cwd));
            printf("%s%c ", cwd, '%');
        }
        cmd = fgets(buffer, BUFSIZE, stdin);
    }

    return EXIT_SUCCESS;
}