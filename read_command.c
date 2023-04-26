#include "simple_shell.h"

/**
 * read_command - Reads a command from standard input
 * @buffer: A pointer to the buffer to store the command
 * @count: A pointer to the size of the buffer
 *
 * Return: The number of characters read, or -1 on failure
 */
ssize_t read_command(char **buffer, size_t *count)
{
    return getline(buffer, count, stdin);
}
