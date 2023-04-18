#include <stdio.h>
#include<stddef.h>

#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i = i + 1;
	}
	return (0);
}
