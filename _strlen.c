#include "main.h"

/**
 * _strlen - returns string length
 * @s: string
 * Return: len
 */

int _strlen(const char *s)
{
	size_t len = 0;

	while (s && *(s + len))
	{
		len++;
	}
	return (len);
}
