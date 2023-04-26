#include "simple_shell.h"

/**
 * read_input - Reads user input
 * Return: The input string, or NULL if EOF is reached
 */
char *read_input(void)
{
    char *buffer = NULL;
    size_t count = 0;
    ssize_t chars_read;
    
    chars_read = getline(&buffer, &count, stdin);

    if (chars_read == -1)
    {
        free(buffer);
        return NULL;
    }

    return buffer;
}

/**
 * free_memory - Frees the memory allocated for command and arguments
 * @argv: The command and its arguments
 * @num_tokens: The number of tokens
 * @str_parse: The parsed string
 */
void free_memory(char **argv, int num_tokens, char *str_parse)
{
    int i;
    
    for (i = 0; i < num_tokens; i++)
    {
        free(argv[i]);
    }
    free(argv);
    free(str_parse);
}
