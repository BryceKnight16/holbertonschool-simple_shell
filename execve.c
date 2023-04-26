#include "simple_shell.h"

/**
 * execute_command - Executes a command
 * @argv: The tokenized command arguments
 */
void execute_command(char **argv)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
