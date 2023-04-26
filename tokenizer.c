#include "simple_shell.h"

/**
 * tokenize_input - Tokenizes the input string
 * @input: The input string
 * @num_tokens: Pointer to store the number of tokens
 * Return: A NULL-terminated array of tokens
 */
char **tokenize_input(char *input, int *num_tokens)
{
    const char *delim = " \n";
    char *token;
    int i;

    *num_tokens = 0;
    token = strtok(input, delim);
    while (token != NULL)
    {
        (*num_tokens)++;
        token = strtok(NULL, delim);
    }
    (*num_tokens)++;

    char **argv = malloc(sizeof(char *) * (*num_tokens));
    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    return argv;
}