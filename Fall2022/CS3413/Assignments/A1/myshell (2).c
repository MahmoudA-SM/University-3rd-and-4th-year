#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#define BUFSIZE 81
#define CWDSIZE 256
#define MAXPARA 100
int status;
int processID;
int numChildren = 0;
int isSuspended = 0;
void handleSignal(int signalNumber)
{
    if (numChildren == 0)
    {
        printf("\nNo jobs to suspend %d\n", signalNumber);
        char cwd[CWDSIZE];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s%c", cwd, '%');
        }
    }
    else
    {
        printf("\nCurrent task suspend\n");
        status = 0;
        numChildren--;
        isSuspended = 1;
    }

    fflush(stdout);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler = &handleSignal;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);
    char *cmd;
    int length;
    char buffer[BUFSIZE]; // room for 80 chars plus \0
    // int processID;
    int return_code;
    char cwd[CWDSIZE];
    int prevFD;

    // signal(SIGTSTP, handleSignal);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s%c", cwd, '%');
    }

    cmd = fgets(buffer, BUFSIZE, stdin);
    // printf("CMD: %s\n", cmd);

    while (cmd != NULL)
    {
        length = strlen(buffer);
        if (buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        char *token2;
        char *commandList[MAXPARA];
        char *rest2 = cmd;
        int commandCount = 0;
        while ((token2 = strtok_r(rest2, "|", &rest2)))
        {
            commandList[commandCount] = token2;
            commandCount++;
        }

        int fd[commandCount][2];

        int i;
        for (i = 0; i < commandCount; i++)
        {
            pipe(fd[i]);

            char *token;
            char *argumentList[commandCount][MAXPARA];
            char *rest = commandList[i];
            int argCount = 0;
            while ((token = strtok_r(rest, " ", &rest)))
            {
                argumentList[i][argCount] = token;
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

                argCount++;
            }

            argumentList[i][argCount] = NULL;

            numChildren++;
            processID = fork();

            if (processID == 0)
            { // child
                status = 1;
                printf("Status in child: %d\n", status);
                if (strcmp(argumentList[i][0], "cd") != 0 && isSuspended == 0)
                {

                    if (i < commandCount - 1)
                    {
                        printf("first:%d", fd[i][1]);
                        dup2(fd[i][1], 1);
                    }
                    if (i > 0)
                    {
                        dup2(prevFD, 0);
                    }

                    return_code = execvp(argumentList[i][0], argumentList[i]);

                    close(prevFD);

                    if (return_code != 0)
                    {
                        printf("Error executing command : %s\n", argumentList[i][0]);
                        perror("error");
                        exit(0);
                    }
                }
                else
                {
                    if (isSuspended == 1)
                        printf("Not allowed to do a job while another is suspended.\n");
                    else
                        exit(0);
                }
            }

            else if (processID != 0)
            { // parent
                // signal(SIGTSTP,signalHandler);

                waitpid(processID, &status, WUNTRACED);
                if (numChildren > 0)
                    numChildren--;
                prevFD = fd[i][0];
                // perror("er");
                // printf("Status in parent: %d\n", status);
                close(fd[i][1]);
                if (i > 0)
                {
                    close(fd[i - 1][0]);
                }
            }

            // status = 0;
        }

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s%c", cwd, '%');
        }
        cmd = fgets(buffer, BUFSIZE, stdin);
    }
    return EXIT_SUCCESS;
}
