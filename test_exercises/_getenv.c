#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *env_var, *token;
	i = 0;
	while (environ[i] != NULL)
	{
		env_var = strdup(environ[i]);
		token = strtok(env_var, "=");
		if (strcmp(token, name) == 0)
		{
			printf("variable: %s\n", token);
			token = strtok(NULL, "=");
			printf("value: %s\n", token);
			free(env_var);
			return (token);
		}
		free(env_var);
		i = i + 1;
	}
	return (NULL);
}
int main(int argc, char *argv[])
{
	char *var_value;

	var_value = _getenv(argv[1]);
	printf("value of main: %s\n", var_value);
	return (0);
}
