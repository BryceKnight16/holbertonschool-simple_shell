#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **tokenize(char *input);
void execute(char **args);
void free_args(char **args);

#endif /* SIMPLE_SHELL_H */
