#include "simple_shell.h"

/**
 * _getenv - Function that gets an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Value of the environment variable, NULL if not found.
 */

char *_getenv(char *name)
{
	int i = 0;
	char *env_var;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0)
		{
			env_var = &environ[i][strlen(name) + 1];
			return (strdup(env_var));
		}
		i = i + 1;
	}
	return (NULL);
}
/**
 * is_a_path - Function that checks if a path is absolute.
 * @path: Path to check.
 *
 * Return: 1 if path is absolute, 0 otherwise.
 */

int is_a_path(char *path)
{
	if (path == NULL || strlen(path) == 0)
	{
		return (0);
	}
	if (path[0] == '/')
	{
		return (1);
	}
	if (path[0] == '.')
	{
		return (1);
	}
	return (0);
}

/**
 * is_executable - checks if a file is executable
 * @file_path: the path of the file to check
 *
 * Return: 1 if the file is executable, 0 otherwise
 */

int is_executable(char *file_path)
{
	struct stat st;

	if (stat(file_path, &st) == 0 && st.st_mode & S_IXUSR)
	{
		return (1);
	}
	return (0);
}

/**
 * search_path - Function that searches for a command in the PATH.
 * @command: Command to search for.
 *
 * Return: Full path of the command if found, NULL otherwise.
 */
char *search_path(char *command)
{
	char *path, *token, *test_path;

	if (is_a_path(command))
	{
		test_path = strdup(command);
		if (test_path == NULL)
		{
			return (NULL);
		}
		if (is_executable(test_path))
		{
			return (test_path);
		}
		free(test_path);
		return (NULL);
	}

	path = _getenv("PATH");
	if (path == NULL || strlen(path) == 0)
	{
		if (is_executable(command))
		{
			return (strdup(command));
		}
		return (NULL);
	}
	test_path = malloc(sizeof(*test_path) * (strlen(path) + strlen(command) + 2));
	if (test_path == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		sprintf(test_path, "%s/%s", token, command);
		if (is_executable(test_path))
		{
			free(path);
			return (test_path);
		}
		token = strtok(NULL, ":");
	}
	free(path);
	free(test_path);
	return (NULL);
}

/**
 * execute_command - Function that executes a command.
 * @argv: Array of arguments.
 * @shell_name: name of our shell.
 * Return: 0 on success
 */

int execute_command(char **argv, char *shell_name)
{
	pid_t pid;
	char *full_path = NULL;
	int status;

	if (strcmp(argv[0], "exit") == 0)
	{
		_exit(0);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	full_path = search_path(argv[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", shell_name, argv[0]);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror("execve");
			return (127);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
		free(full_path);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (128 + WTERMSIG(status));
		}
	}
	else
	{
		perror("fork");
		free(full_path);
		return (-1);
	}
	return (0);
}
