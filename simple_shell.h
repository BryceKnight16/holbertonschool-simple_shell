#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_prompt(void);
ssize_t read_command(char **buffer, size_t *count);
void tokenize_command(char *buffer, char ***argv);

#endif /* SIMPLE_SHELL_H */
