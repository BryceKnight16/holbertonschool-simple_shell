#include "simple_shell.h"

/**
 * count_tokens - Counts the number of tokens in a string
 * @str: The input string
 * @delim: The delimiter string
 * Return: The number of tokens
 */
char **tokenize_input(char *input, int *num_tokens)
{
    const char *delim = " \n";
    char *token;
    int i;
    char **argv = NULL;
    
    *num_tokens = 0;

    token = strtok(input, delim);
    while (token != NULL)
    {
        *num_tokens = num_tokens + 1;
        token = strtok(NULL, delim);
    }
     *num_tokens = num_tokens + 1;

    argv = malloc(sizeof(char *) * (*num_tokens));
    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        printf(" argv[%d] %s\n", i, argv[i]);
        token = strtok(NULL, delim);
    }
    
    argv[i] = NULL;

    return argv;
}
