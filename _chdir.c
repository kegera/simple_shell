#include "main.h"

/**
 * _chdir - changes directory
 * @arguments: args
 * Return: 1 else 0
 */
int _chdir(char **arguments)
{
	char *c_dir = getcwd(NULL, 0);
	char *p_dir = getenv("OLDPWD");
	const char *_home = getenv("HOME");

	if (arguments[1] == NULL)
	{
		if (_home != 0)
		{
			perror("cd");
		}
	}
	else if (_strcmp(arguments[1], "-") == 0)
	{
		if (p_dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
		else
		{
			if (chdir(p_dir) != 0)
			{
				perror("cd");
			}
			write(STDOUT_FILENO, p_dir, _strlen(p_dir));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		if (chdir(arguments[1]) != 0)
		{
			perror("cd");
		}
	}
	if (c_dir == NULL)
	{
		perror("cd: getcwd error");
		exit(EXIT_FAILURE);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", c_dir, 1);
	free(c_dir);
	return (1);
}
