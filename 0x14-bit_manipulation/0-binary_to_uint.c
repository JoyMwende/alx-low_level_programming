#include "main.h"

/**
 * binary_to_uint - convert binary number to unsigned int
 * @b: pointer to string
 * Return: converted number
 * return 0 if there's more than 1 char in b
 * return 1 if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int gh;
	int count, j;

	if (!b)
		return (0);

	gh = 0;

	for (count = 0; b[count] != '\0'; count++)
		;
	for (count--, j = 1; count >= 0; count--, j *= 2)
	{
		if (b[count] != '0' && b[count] != '1')
			return (0);

		if (b[count] & 1)
			gh += j;
	}

	return (gh);
}
