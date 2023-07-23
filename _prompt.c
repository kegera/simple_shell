#include "main.h"

/**
 * _prompt - displays prompt
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
