#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - main function for the simple shell
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */
int main(int ac, char **argv)
{
    char *shell_prompt = "$ ";
    char *buffer = NULL;
    size_t count = 0;
    ssize_t chars_read;
    
    char *str_parse = NULL;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    while (1)
    {
        printf("%s", shell_prompt);
        chars_read = getline(&buffer, &count, stdin);

        if (chars_read == -1)
        {
            putchar('\n');
            break;
        }

        str_parse = strdup(buffer);
        if (str_parse == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }

        token = strtok(buffer, delim);
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);
        token = strtok(str_parse, delim);
        for (i = 0; token != NULL; i++)
        {
            argv[i] = strdup(token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        pid_t pid = fork();
        if (pid == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
            {
                printf("%s: No such file or directory\n", argv[0]);
            }
            exit(0);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror("fork");
            return (-1);
        }

        for (i = 0; i < num_tokens; i++)
        {
            free(argv[i]);
        }
        free(argv);
        free(str_parse);
    }

    free(buffer);

    return (0);
}
