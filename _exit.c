#include "main.h"

/**
 * status - exits shell
 * @buffer: pointer to args
 * Return: 0 on success else -1
 */

int status(char **buffer)
{
	int exit_code;
	const char *err = "hsh: exit: numeric argument required\n";

	if(buffer[1] == NULL)
	{
		exit(0);
	}
	else
	{
		exit_code = _atoi(buffer[1]);

		if (exit_code == 0 && buffer[1][0] != 0)
		{
			write(STDERR_FILENO, err, _strlen(err));
			return (2);
		}
		exit(exit_code);
	}
	return (0);
}
