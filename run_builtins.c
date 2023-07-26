#include "main.h"

/**
 * run_builtins - executes builtin commands
 * @args: arguments
 * Return: 1 else 0
 */

int run_builtins(char **args)
{
	int b;
	char **cmd1 = args, **cmd2 = NULL;

	if (args[0] == NULL)
	{
		return (1);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		return (_chdir(args));
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		return (execute_env(args));
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (print_args(args));
	}
	else if (cmd2 != NULL)
	{
		return (pipe_builtin(cmd1, cmd2));
	}
	else
	{
		return (process(args));
	}
	for (b = 0; args[b] != NULL; b++)
	{
		if (_strcmp(args[b], "|") == 0)
		{
			args[b] = NULL;
			cmd2 = &args[b + 1];
			break;
		}
	}
}
