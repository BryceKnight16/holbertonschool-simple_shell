#include "simple_shell.h"

/**
 * tokenize_command - Tokenizes a command
 * @buffer: The command buffer
 * @argv: A pointer to the array of tokenized command strings
 */
void tokenize_command(char *buffer, char ***argv)
{
    char *str_parse = NULL;
    const char *delim = " ";
    int num_tokens = 0;
    char *token;
    int i;

    str_parse = malloc(sizeof(char) * strlen(buffer));
    strcpy(str_parse, buffer);

    token = strtok(buffer, delim);
    while (token != NULL)
    {
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;

    *argv = malloc(sizeof(char *) * num_tokens);
    token = strtok(str_parse, delim);
    for (i = 0; token != NULL; i++)
    {
        (*argv)[i] = malloc(sizeof(char) * strlen(token));
        strcpy((*argv)[i], token);
        token = strtok(NULL, delim);
    }
    (*argv)[i] = NULL;

    free(str_parse);
}
