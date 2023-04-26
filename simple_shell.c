#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
    char *buffer = NULL;
    size_t count = 0;
    ssize_t chars_read;
    char **parsed_argv = NULL;
    int i;

    while (1)
    {
        display_prompt();
        chars_read = read_command(&buffer, &count);

        if (chars_read == -1)
        {
            printf("Command not found\n");
            return (-1);
        }

        tokenize_command(buffer, &parsed_argv);
	execute_command(parsed_argv);

        /* printf("%s\n", buffer); */

        /* Free allocated memory */
        i = 0;
	while (parsed_argv[i] != NULL)
	{
		free(parsed_argv[i]);
		i++;
	}
	free(parsed_argv);
    }

    free(buffer);

    return (0);
}
