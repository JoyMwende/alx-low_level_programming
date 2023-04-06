#include "main.h"

/**
 * set_bit - set bit value to 1
 * @n: int
 * @index: index from0
 * Return: 1 on success
 * -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int l;

	if (index > 63)
		return (-1);

	l = 1 << index;
	*n = (*n | l);

	return (1);
}
