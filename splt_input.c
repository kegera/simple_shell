#include "main.h"

/**
 * split_input - tokenizes user input
 * @input: user input
 * Return: input split
 */

char **split_input(char *input)
{
	int c = 0, size = BUFFER_SIZE;
	char **token = malloc(size * sizeof(char *)), *split;

	if (!token)
	{
		perror("split_input");
		exit(EXIT_FAILURE);
	}
	split = strtok(input, DELIMITER);
	while (split != NULL)
	{
		if (split[0] == '#')
		{
			break;
		}
		token[c] = split;
		c++;

		if (c >= size)
		{
			size += BUFFER_SIZE;
			token = realloc(token, size * sizeof(char *));
			if (!token)
			{
				perror("token");
				exit(EXIT_FAILURE);
			}
		}
		split = strtok(NULL, DELIMITER);
	}
	token[c] = NULL;
	return (token);
}
