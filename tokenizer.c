#include "simple_shell.h"

/**
 * tokenize - Tokenizes the input string
 * @input: The input string
 * Return: The array of tokens, or NULL on failure
 */
char **tokenize(char *input)
{
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    
    char *str_parse = strdup(input);
    if (str_parse == NULL)
    {
        return NULL;
    }

    token = strtok(input, delim);
    while (token != NULL)
    {
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;

    char **args = malloc(sizeof(char *) * num_tokens);
    if (args == NULL)
    {
        free(str_parse);
        return NULL;
    }

    token = strtok(str_parse, delim);
    for (int i = 0; token != NULL; i++)
    {
        args[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    args[num_tokens - 1] = NULL;

    free(str_parse);

    return args;
}
