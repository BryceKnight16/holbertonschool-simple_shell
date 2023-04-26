#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 * Return: 0 on success, -1 on failure
 */
int main(int ac, char **argv)
{
    char *shell_prompt = "$ ";
    char *buffer = NULL;
    char *str_parse = NULL;
    int num_tokens = 0;
    char **argv;
    int is_interactive;
    int status;

    while (1)
    {
        is_interactive = isatty(STDIN_FILENO);
        if (is_interactive)
        {
            printf("%s", shell_prompt);
        }
        
        if (buffer == NULL)
            break;

        if (strcmp(buffer, "exit\n") == 0)
        {
            free(buffer);
            break;
        }

        str_parse = strdup(buffer);
        argv = tokenize_input(str_parse, &num_tokens);
        status = execute_command(argv);
        free_memory(argv, num_tokens, str_parse);

        free(buffer);
        if (!is_interactive && status != -1)
        {
            break;
        }
    }

    return (0);
}
