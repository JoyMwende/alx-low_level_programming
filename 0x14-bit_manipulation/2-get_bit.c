#include "main.h"

/**
 * get_bit - return bit value at certain index
 * @n: integer
 * @index: index from 0
 * Return: index value
 * -1 if there's an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int q;

	if (index > 64)
		return (-1);
	q = (n >> index) & 1;

	return (q);
}
