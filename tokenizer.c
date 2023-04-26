#include "simple_shell.h"

/**
 * count_tokens - Counts the number of tokens in a string
 * @str: The input string
 * @delim: The delimiter string
 * Return: The number of tokens
 */
list_t *tokenize_input(char *input)
{
    const char *delim = " \n";
    char *token;
    list_t *head = NULL;

    token = strtok(input, delim);
    while (token != NULL)
    {
	add_node_end(&head, token);
        token = strtok(NULL, delim);
    }

    return (head);
}
