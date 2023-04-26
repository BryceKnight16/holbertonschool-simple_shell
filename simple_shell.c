#include "simple_shell.h"
/**
 * is_interactive - check if interactive or not
 *
 * Description: check if it an interactive or not
 * Return: 
 **/

void is_interactive(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("$ ");
	}

	return;
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
	int listt_len = list_len(head);
        char **argv = malloc(sizeof(char *) * (list_len + 1));

        int i;
        for (i = 0; head != NULL; i++)
        {
            argv[i] = head->str;
            head = head->next;
        }
        argv[i] = NULL;


        free(argv);
        free(buffer);
        free_list(head);
    }
    return (0);
}
