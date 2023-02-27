#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: string to print
 * Return: no return
 */

void puts_half(char *str)
{
	int len = 0, n;

	while (len >= 0)
	{
		if (str[len] == '\0')
			break;
		len++;
	}

	if (len % 2 == 1)
		n = len / 2;
	else
		n = (len - 1) / 2;

	for (n++; n < len; n++)
		_putchar(str[n]);
	_putchar('\n');
}
