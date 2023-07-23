#include "main.h"

/**
 * pipe_builtin - handles the pipe builtin
 * @cmd1: first argument
 * @cmd2: second argument
 * Return: 0
 */

int pipe_builtin(char **cmd1, char **cmd2)
{
	int _pipe[2], status;
	pid_t pid1, pid2;

	if (pipe(_pipe) != -1)
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			close(_pipe[0]);
			dup2(_pipe[1], STDOUT_FILENO);
			close(_pipe[1]);

			execve(cmd1[0], cmd1, environ);
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		else if (pid1 < 0)
		{
			perror("fork");
			return (-1);
		}
		pid2 = fork();
		if (pid2 == 0)
		{
			close(_pipe[1]);
			dup2(_pipe[0], STDIN_FILENO);
			close(_pipe[0]);

			execve(cmd2[0], cmd2, environ);
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		else if (pid2 < 0)
		{
			perror("fork");
			return (-1);
		}
		close(_pipe[0]);
		close(_pipe[1]);

		waitpid(pid1, NULL, 0);
		waitpid(pid2, &status, 0);

		return (WEXITSTATUS(status) == 0);
	}
	else
	{
		perror("pipe");
		return (-1);
	}
}
