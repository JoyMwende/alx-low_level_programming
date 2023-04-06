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

	if (n == 0 && index < 64)
		return (0);

	for (q = 0; q <= 63; n >>= 1, q++)
	{
		if (index == 1)
			return (n & 1);
	}

	return (-1);
}
