#include "main.h"

/**
 * _strncat - concenate two strings
 * @dest: destination
 * @src: source
 * @n: amount of bytes used from src
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int length = 0, length2 = 0;

	while (*(dest + length) != '\0')
	{
		length++;
	}

	while (length2 < n)
	{
		*(dest + length) = *(src + length2);
		if (*(src + length2) == '\0')
			break;
		length++;
		length2++;
	}
	return (dest);
}
