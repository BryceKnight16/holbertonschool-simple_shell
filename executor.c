#include "simple_shell.h"

/**
 * execute - Executes the command
 * @args: The array of command arguments
 */
void execute(char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            printf("%s: No such file or directory\n", args[0]);
        }
        exit(0);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork");
    }
}
