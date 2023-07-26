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
	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	int ch;
	char *line = NULL, *line2;

	if (lineptr != NULL && n != NULL && stream != NULL)
	{
		while ((ch = getc(stream)) != EOF)
		{
			if ((size_t)bytes_read + 1 >= buffer_size)
			{
				buffer_size = (buffer_size + 1) * 2;
				line2 = realloc(line, buffer_size);

				if (!line2)
				{
					free(line);
					return (-1);
				}
				line = line2;
			}
			line[bytes_read++] = ch;

			if (ch == '\n')
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
		*n = buffer_size;
		return (bytes_read);
	}
	else
	{
		errno = EINVAL;
		return (-1);
	}
}
