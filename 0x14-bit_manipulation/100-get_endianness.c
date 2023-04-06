#include "main.h"

/**
 * get_endianness - check endianness
 * Return: 0 for endian big
 * 1 for endian small
 */

int get_endianness(void)
{
	unsigned int f;
	char *g;

	f = 1;
	g = (char *) &f;

	return ((int)*g);
}
