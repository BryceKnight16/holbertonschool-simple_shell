#include "simple_shell.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

/**
 * is_interactive - prints shell prompt if in interactive mode
 */
void is_interactive(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$ ");
		fflush(stdout);
	}
}

/**
 * main - Entry point for the simple shell
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *buffer = NULL;
	char *str_parse = NULL;
	list_t *head;
	char **argv;
	int i;

	while (1)
	{
		is_interactive();
		buffer = read_input();

		if (buffer == NULL)
			break;

		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}

		str_parse = strdup(buffer);
		head = tokenize_input(str_parse);
		if (head != NULL)
		{
			argv = malloc(sizeof(char *) * (list_len(head) + 1));

			for (i = 0; head != NULL; i++)
			{
				argv[i] = head->str;
				head = head->next;
			}
			argv[i] = NULL;

			execute_command(argv);

			free(argv);
		}

		free(buffer);
		free_list(head);
	}

	return (0);
}
