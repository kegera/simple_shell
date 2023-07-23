#include "main.h"

/**
 * _strcmp - compares two str inputs
 * @s1: string 1
 * @s2: string 2
 * Return: negative value is s1 < s2, else positive value
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

