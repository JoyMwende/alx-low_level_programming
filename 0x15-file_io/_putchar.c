#include <unistd.h>

/**
 * _putchar = writes char c to stdout
 * @c: char to print
 *
 * Return: on success 1
 * on error -1 and errno is ser appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
