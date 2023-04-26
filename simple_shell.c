#include "simple_shell.h"

/**
 * main - main function for the simple shell
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */
int main(int ac, char **argv)
{
    char *shell_prompt = "$ ";
    char *buffer = NULL;
    size_t count = 0;
    ssize_t chars_read;
   

    while (1)
    {
        printf("%s", shell_prompt);
        chars_read = getline(&buffer, &count, stdin);

        if (chars_read == -1)
        {
            putchar('\n');
            break;
        }

        char argv = tokenize(buffer);
        if (argv == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }

        execute(args);

        free_args(args);
    }

    free(buffer);

    return (0);
}
