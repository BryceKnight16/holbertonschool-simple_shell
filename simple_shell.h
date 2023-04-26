#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
char *read_input(void);
list_t *tokenize_input(char *input);
void execute_command(char **argv);
void free_list(list_t *head)


#endif /* SIMPLE_SHELL_H */
