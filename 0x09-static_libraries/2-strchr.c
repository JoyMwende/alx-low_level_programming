#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character
 * Return: pointer to the first occurrencef character c in string s
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	unsigned int a;

	for (a = 0; *(s + a) != '\0'; a++)
		if (*(s + a) == c)
			return (s + a);
	if (*(s + a) == c)
		return (s + a);
	return ('\0');
}
