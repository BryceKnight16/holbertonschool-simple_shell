#include "simple_shell.h"

/**
 * execute_command - Executes the given command
 * @argv: The command and its arguments
 */
void execute_command(char **argv)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
            printf("%s: No such file or directory\n", argv[0]);

        exit(0);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork");
        exit(-1);
    }
}
