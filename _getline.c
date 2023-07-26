#include "main.h"

/**
 * _getline - allocates memory to a line from stream
 * @lineptr: pointer to buffer
 * @n: buffer size
 * @stream: stream
 * Return: char count else -1
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFSIZ];
	static size_t buffer_size;
	ssize_t bytes_read = 0;
	int ch;
	char *line = NULL, *line2;

	if (lineptr != NULL && n != NULL && stream != NULL)
	{
		while ((ch = getc(stream)) != EOF)
		{
			if (buffer_size == 0)
			{
				buffer_size = fread(buffer, 1, BUFSIZ, stream);
				if (buffer_size == 0)
					break;
				bytes_read = 0;
			}
			if ((size_t)bytes_read + 1 >= *n)
			{
				*n = (*n + 1) * 2;
				line2 = realloc(line, *n);

				if (!line2)
				{
					free(line);
					return (-1);
				}
				line = line2;
			}
			line[bytes_read++] = buffer[buffer_size - 1];
			buffer_size--;

			if (line[bytes_read - 1] == '\n')
			{
				break;
			}
		}
		if (bytes_read == 0)
		{
			free(line);
			return (-1);
		}
		line[bytes_read] = '\0';
		*lineptr = line;
		return (bytes_read);
	}
	else
	{
		errno = EINVAL;
		return (-1);
	}
}
