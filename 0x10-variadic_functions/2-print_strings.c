#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int a;
	char *s;

	if (n > 0)
	{
		va_start(valist, n);
		for (a = 1; a <= n; a++)
		{
			s = va_arg(valist, char *);
			if (s == NULL)
				printf("(nul)");
			else
				printf("%s", s);

			if (a != n && separator != NULL)
				printf("%s", separator);
		}
		va_end(valist);
	}
	printf("\n");
}
