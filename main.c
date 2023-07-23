#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument array
 * Return: success
 */

int main(int argc, char **argv)
{
	char *gline;
	char **args;

	if (argc > 1)
	{
		get_input(argv[1]);
	}
	do {
		_prompt();
		gline = read_input();
		args = split_input(gline);
		run_builtins(args);

		free(gline);
		free(args);
	} while (1);
	return (EXIT_SUCCESS);
}
