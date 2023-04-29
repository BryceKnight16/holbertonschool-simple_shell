#include "simple_shell.h"

/**
 * print_env - Prints the current environment variables
 */
void print_env(void)
{
    int i;

    i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

