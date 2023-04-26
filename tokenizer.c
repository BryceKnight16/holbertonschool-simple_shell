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
        (*num_tokens)++;
        token = strtok(NULL, delim);
    }

    argv = malloc(sizeof(char *) * (*num_tokens + 1));
    if (argv == NULL)
    {
        fprintf(stderr, "Error: malloc() failed\n");
        return NULL;
    }

    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        if (argv[i] == NULL)
        {
            fprintf(stderr, "Error: strdup() failed\n");
            for (int j = 0; j < i; j++)
            {
                free(argv[j]);
            }
            free(argv);
            return NULL;
        }
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    return argv;
}
