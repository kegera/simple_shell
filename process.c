#include "main.h"

/**
 * process - starts new process
 * @args: arguments
 * Return: 0
 */

int process(char **args)
{
	char **environ = NULL, *pathc, *path, *_dir;
	pid_t pid;
	int _status;

	pid = fork();

	if (_strcmp(args[0], "exit") == 0)
	{
		return (status(args));
	}
	if (pid == 0)
	{
		path = getenv("PATH");
		_dir = strtok(path, ":");

		while (_dir != NULL)
		{
			pathc = malloc(_strlen(_dir) + _strlen(args[0]) + 2);
			sprintf(pathc, "%s/%s", _dir, args[0]);

			if (access(pathc, X_OK) == 0)
			{
				args[0] = pathc;
				break;
			}
			free(pathc);
			_dir = strtok(NULL, ":");
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &_status, WUNTRACED);
		} while (!WIFEXITED(_status) && !WIFSIGNALED(_status));
	}
	return (0);
}
