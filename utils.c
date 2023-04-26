#include "simple_shell.h"

/**
 * read_input - Reads user input
 * Return: The input string, or NULL if EOF is reached
 */
char *read_input(void)
{
    char *buffer = NULL;
    size_t count = 0;
    ssize_t chars_read;
    
    chars_read = getline(&buffer, &count, stdin);

    if (chars_read == -1)
    {
        return NULL;
    }

    return buffer;
}
