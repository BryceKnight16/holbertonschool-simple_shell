#include "simple_shell.h"

/**
 * tokenize_input - Tokenizes the input string
 * @input: The input string
 * @num_tokens: Pointer to store the number of tokens
 * Return: A NULL-terminated array of tokens
 */

char **tokenize_input(char *input, int *num_tokens)
{
    const char *delim = " ";
    char *token;
    int i;
    char **argv;

    input[strlen(input)-1] = '\0'; // add null character to terminate string

    *num_tokens = 0;
    token = strtok(input, delim);
    while (token != NULL)
    {
        (*num_tokens)++;
        token = strtok(NULL, delim);
    }
    (*num_tokens)++;

    argv = malloc(sizeof(char *) * (*num_tokens));
    if (argv == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }

    token = strtok(input, delim);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = strdup(token);
        if (argv[i] == NULL) {
            fprintf(stderr, "Error: malloc failed\n");
            return NULL;
        }
        token = strtok(NULL, delim);
    }
    printf("%s", argv[0]);
    printf("%s", argv[1]);
    argv[i] = NULL;

    return argv;
}

