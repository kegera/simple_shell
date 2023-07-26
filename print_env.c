#include "main.h"

/**
 * execute_env - builtin env
 * @args: array
 * Return: 1 else 0
 */

int execute_env(char **args)
{
	char **env = environ;

	if (!args[1])
	{
		while (*env)
		{
			size_t i = _strlen(*env);

			write(STDOUT_FILENO, *env, i);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	return (1);
}
