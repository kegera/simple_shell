#include "main.h"

/**
 * _chdir - changes directory
 * @arguments: args
 * Return: 1 else -1
 */

int _chdir(char **arguments)
{
	char *c_dir = getcwd(NULL, 0);
	char *p_dir = getenv("OLDPWD");
	const char *_home = getenv("HOME");

	if (arguments[1])
	{
		if(_strcmp(arguments[1], "-") == 0)
		{
			if (p_dir == NULL)
			{
				write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
			}
			else
			{
				if (chdir(p_dir) != 0)
				{
					perror("_chdir");
				}
				else
				{
					write(STDOUT_FILENO, p_dir, _strlen(p_dir));
					write(STDOUT_FILENO, "\n", 1);
				}
			}
		}
		else if (_strcmp(arguments[1], "~") == 0)
		{
			if (_home == NULL)
			{
				perror("cd: Home not set");
			}
			else
			{
				if (chdir(_home) != 0)
				{
					perror("cd");
				}
			}
		}
		else
		{
			if (chdir(arguments[1]) != 0)
			{
				perror("_chdir");
			}
		}
	}
	else
	{
		if (_home == NULL)
		{
			perror("cd: Home not set");
		}
		else
		{
			if (chdir(_home) != 0)
			{
				perror("cd");
			}
		}
	}
	if (c_dir == NULL)
	{
		perror("_chdir: getcwd error");
		exit(EXIT_FAILURE);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", c_dir, 1);
	return (1);
}
