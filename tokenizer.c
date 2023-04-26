#include "simple_shell.h"

/**
 * tokenize - Tokenizes the input string
 * @input: The input string
 * Return: The array of tokens, or NULL on failure
 */
char **tokenize(char *input)
{
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	char **args

	char *str_parse = strdup(input);
	if (str_parse == NULL)
	{
		return NULL;
	}

	token = strtok(input, delim);
	while (token != NULL)
	{
		num_tokens = num_tokens + 1;
		token = strtok(NULL, delim);
	}
	num_tokens = num_tokens + 1;

	char **args = malloc(sizeof(char *) * num_tokens);
	if (args == NULL)
	{
		free(str_parse);
		return NULL;
	}

	token = strtok(str_parse, delim);
	int i = 0;
	while (token != NULL)
	{
		args[i] = strdup(token);
		token = strtok(NULL, delim);
		i = i + 1;
	}

	args[num_tokens - 1] = NULL;

	free(str_parse);

	return (args);
}
