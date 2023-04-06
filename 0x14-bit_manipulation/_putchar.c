#include <unistd.h>

/**
 * _putchar - writes char c to stdout
 * @c: character to print
 *
 * Return: on success 1
 * On error, return -1 and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
