#include "main.h"

/**
 * flip_bits - return no of bits needed to flip
 * @n: first integer
 * @m: second integer
 * Return: bits no
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int rbits;

	for (rbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			rbits++;
	}

	return (rbits);
}
