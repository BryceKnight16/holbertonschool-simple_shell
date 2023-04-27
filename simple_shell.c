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
char **list_to_array(list_t *head)
{
	char **array;
	int i;

	array = malloc(sizeof(*array) * (list_len(head) + 1));

	i = 0;
	while (head != NULL)
	{
		array[i] = strdup(head->str);
		i = i + 1;
		head = head->next;
	}
	array[i] = NULL;
	return (array);
}

void free_array(char **array)
{
	int i;

	i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i = i + 1;
	}
	free(array);

}
/**
 * main - Entry point for the simple shell
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *buffer = NULL;
	list_t *head;
	char **argv;

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

		head = tokenize_input(buffer);
		if (head != NULL)
		{
			argv = list_to_array(head);
			free_list(head);
			execute_command(argv);
			free_array(argv);
		}

		free(buffer);
	}

	return (0);
}
