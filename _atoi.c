#include "main.h"

/**
 * _atoi - converts a string to a number
 * @s: string to be converted
 * Return: int
 */

int _atoi(char *s)
{
	int x = 0;
	unsigned int y = 0;
	int i = 1;
	int j = 0;

	while (s[x])
	{
		if (s[x] == 45)
		{
			i *= -1;
		}
		while (s[x] >= 48 && s[x] <= 57)
		{
			j = 1;
			y = (y * 10) + (s[x] - '0');
			x++;
		}
		if (j == 1)
		{
			break;
		}
		x++;
	}
	y *= i;
	return (y);
}
