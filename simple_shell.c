#include "simple_shell.h"
/**
 * is_interactive - check if interactive or not
 *
 * Description: check if it an interactive or not
 * Return: 
 **/

void is_interactive(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$ ");
	}

	return;
}

/**
 * main - Entry point for the simple shell
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
    char *buffer = NULL;
    char *str_parse = NULL;
    int num_tokens = 0;
    char **argv;

   

    while (1)
    {
	is_interactive();
        buffer = read_input();
	
        if (buffer == NULL)
            break;

        if (strcmp(buffer, "exit\n") == 0)
        {
            free(buffer);
            break;
        }

        str_parse = strdup(buffer);
        argv = tokenize_input(str_parse, &num_tokens);
        execute_command(argv);
        free_memory(argv, num_tokens, str_parse);

        free(buffer);
    }

    return (0);
}
