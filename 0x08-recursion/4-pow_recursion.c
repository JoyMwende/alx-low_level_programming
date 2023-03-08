#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: integer
 * @y: power
 * Return: value of x raised to the power of y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	if (x == 0)
	{
		return (0);
	}
	if (x == 1 || y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, y - 1));
}
