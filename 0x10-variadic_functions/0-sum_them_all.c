#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: parameter
 * Return: sum of all its parameters and 0 if n == 0
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list valist;
	unsigned int x;
	int sum = 0;

	/*validate valist and initialize */
	if (n == 0)
		return (0);

	va_start(valist, n);

	/*iterate through list, update sum, free list*/
	for (x = 0; x < n; x++)
	{
		sum += va_arg(valist, int);
	}

	va_end(valist);

	return (sum);
}
