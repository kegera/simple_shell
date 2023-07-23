#include "main.h"

/**
 * get_input - gets user input
 * @filename: name of file
 * Return: 0
 */

int get_input(char *filename)
{
	FILE *f = fopen(filename, "r");
	char *rd = NULL;
	int check = 0;
	size_t size = 0;

	if (f == NULL)
	{
		while(_getline(&rd, &size, f) != -1)
		{
			char **argv = split_input(rd);

			if (argv[0] != NULL)
			{
				if (_strcmp(argv[0], "exit") == 0)
				{
					check = status(argv);
				}
				else
				{
					check = run_builtins(argv);
				}
			}
			free(argv);
			if (check != 0)
			{
				break;
			}
		}
		free(rd);
		fclose(f);
	}
	else
	{
		perror("get_input");
		return (1);
	}
	return (check);
}
