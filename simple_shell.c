#include "simple_shell.h"

/**
 * free_list - Frees a linked list of strings
 * @head: Head of the list to free
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
 * list_to_array - Converts a linked list of strings to an array of strings
 * @head: Head of the linked list
 *
 * Return: Pointer to an array of strings
 */

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

/**
 * free_array - Frees an array of strings
 * @array: Array of strings to free
 */

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

int main(int argc, char *argv[])
{
    char *buffer = NULL;
    list_t *head;
    char **args;
    char *shell_name = argv[0];
    int exit_code;

    (void)argc;
    exit_code = 0;

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
            args = list_to_array(head);
            free_list(head);
            exit_code = execute_command(args, shell_name);
            free_array(args);
        }
        free(buffer);
    }
    return (exit_code);
}


