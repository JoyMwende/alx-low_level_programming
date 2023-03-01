#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 if s1 and s2 are equals
 * another number if not
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0, x = 0;

	while (x == 0)
	{
		if ((*(s1 + a) == '\0') && (*(s2 + a) == '\0'))
			break;
		x = *(s1 + a) - *(s2 + a);
		a++;
	}

	return (x);
}
