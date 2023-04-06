#include "main.h"

/**
 * clear_bit - set bit val to 0
 * @n: int
 * @index: index from 0
 * Return: 1 on success
 * -1 on error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int l;

	if (index > 63)
		return (-1);

	l = 1 << index;

	if (*n & l)
		*n ^= l;

	return (1);
}
