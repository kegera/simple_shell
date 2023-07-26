#include "main.h"

/**
 * status - exits shell
 * @arguments: pointer to args
 * Return: 0 on success else 1
 */
int status(char **arguments)
{
	int exit_code = 0;
	const char *err = "hsh: exit: numeric argument required\n";

	if (arguments[1] == NULL)
	{
		exit(0);
	}
	else
	{
		exit_code = _atoi(arguments[1]);

		if (exit_code == 0 && arguments[1][0] != '0')
		{
			write(STDERR_FILENO, err, _strlen(err));
			return (2);
		}
	}
	exit(exit_code);
	return (0);
}
