#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void display_prompt(void);
ssize_t read_command(char **buffer, size_t *count);
void tokenize_command(char *buffer, char ***argv);
void execute_command(char **argv);

#endif /* SIMPLE_SHELL_H */
