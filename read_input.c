#include "main.h"

/**
 * read_input - reads user input
 * Return: pointer
 */

char *read_input(void)
{
	char *input = NULL;
	size_t size = 0;

	if (_getline(&input, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror(" read_input");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
