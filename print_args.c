#include "main.h"

/**
 * print_args - prints arguments to stdout
 * @args: array of arguments
 * Return: 0
 */
int print_args(char **args)
{
	int index = 1;
	char pid[20], *envar;
	int pid_len;

	while (args[index] != NULL)
	{
		if (args[index][0] == '$')
		{
			envar = getenv(&args[index][1]);
			if (envar != NULL)
			{
				write(STDOUT_FILENO, envar, _strlen(envar));
			}
		}
		else if (_strcmp(args[index], "$$") == 0)
		{
			pid_len = sprintf(pid, "%d", getpid());
			write(STDOUT_FILENO, pid, pid_len);
		}
		else
		{
			write(STDOUT_FILENO, args[index], _strlen(args[index]));
		}
		if (args[index + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1);
		}
		index++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
