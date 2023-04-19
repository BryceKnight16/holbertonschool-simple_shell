#include <stdio.h>
#include <stdlib.h>
int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");
	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		printf("\nEnd of input reached.\n");
	}
	else
	{
		printf("%s", line);
	}
	free(line);
	return (0);
}
