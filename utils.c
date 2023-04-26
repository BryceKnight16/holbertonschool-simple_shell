#include "simple_shell.h"

/**
 * free_args - Frees the array of arguments
 * @args: The array of arguments
 */
void free_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}
