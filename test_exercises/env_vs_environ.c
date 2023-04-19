#include <stdio.h>
#include <stdlib.h>

/* Declare the environ variable as external */
extern char **environ;

/**
 * main - Entry point
 *
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 * @env: An array of strings containing the environment variables
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[], char *env[])
{
    /* Print the address of the env parameter */
    printf("Address of env: %p\n", &env);

    /* Print the address of the environ variable */
    printf("Address of environ: %p\n", &environ);
    if (&env == &environ)
    {
        printf("Same !!!!!!");
    }
    else
    {
        printf("It's different");
    }

    return (0);
}
