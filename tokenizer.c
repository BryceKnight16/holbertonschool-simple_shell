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
        (*num_tokens) ++;
        token = strtok(NULL, delim);
    }
     (*num_tokens) ++;

    argv = malloc(sizeof(char *) * (*num_tokens));
    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    printf("%s", argv[0]);
    printf("%s", argv[1]);
    argv[i] = NULL;

    return argv;
}
