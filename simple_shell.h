#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_input(void);
char **tokenize_input(char *input, int *num_tokens);
void execute_command(char **argv);
void free_memory(char **argv, int num_tokens, char *str_parse);

#endif /* SIMPLE_SHELL_H */
