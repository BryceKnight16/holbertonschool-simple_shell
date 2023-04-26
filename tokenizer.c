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
<<<<<<< HEAD
	add_node_end(&head, token);
        token = strtok(NULL, delim);
    }

    return (head);
=======
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
>>>>>>> 76df8375440a201b02ef7326637253970c407985
}
