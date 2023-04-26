#include "simple_shell.h"

/**
 * count_tokens - Counts the number of tokens in a string
 * @str: The input string
 * @delim: The delimiter string
 * Return: The number of tokens
 */
int count_tokens(char *str, const char *delim)
{
    int num_tokens = 0;
    char *token;

    token = strtok(str, delim);
    while (token != NULL)
    {
        num_tokens++;
        token = strtok(NULL, delim);
    }

    return num_tokens;
}

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
    char **argv;

    *num_tokens = count_tokens(input, delim);
    argv = malloc(sizeof(char *) * (*num_tokens + 1));

    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        token = strtok(NULL, delim);
    }
  
    argv[i] = NULL;

    return argv;
}

