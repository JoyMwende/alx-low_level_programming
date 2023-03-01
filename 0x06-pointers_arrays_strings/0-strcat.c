#include "main.h"

/**
 * *_strcat - concenates two strings
 * @dest: destination
 * @src: source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, len2 = 0;

	while (*(dest + len) != '\0')
	{
		len++;
	}

	while (len2 >= 0)
	{
		*(dest + len) = *(src + len2);
		if (*(src + len2) == '\0')
			break;
		len++;
		len2++;
	}
	return (dest);
}
