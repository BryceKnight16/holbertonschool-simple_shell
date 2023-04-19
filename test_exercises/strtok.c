#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **split_string(char *str, const char *delim, int *num_of_words)
{
    char **array = NULL;
    char *token;
    int count = 0;
    token = strtok(str, delim);
    while (token != NULL)
    {
        array = realloc(array, (count + 1) * sizeof(char *));
        if (array == NULL)
        {
            printf("ERROR");
        }
        array[count] = token;
        count++;
        token = strtok(NULL, delim);
    }
    *num_of_words = count;
    return array;
}
int main()
{
    char str[] = "Hi, how are you ? can we have a break, I am hungry!!!";
    char **array;
    const char delim[] = " ,!?";
    int num_of_words;
    int i;
    array = split_string(str, delim, &num_of_words);
    for (i = 0; i < num_of_words; i++)
    {
        printf("%s\n", array[i]);
    }
    free(array);
    return 0;
}
