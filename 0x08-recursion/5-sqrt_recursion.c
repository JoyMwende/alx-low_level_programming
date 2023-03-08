#include "main.h"

/**
 * square_root - find sqaure root of n, starting with 0
 * @n: n
 * @root: test this root
 * Return: natural sqaure root of n or -1 if not natural root
 */

int square_root(int n, int root)
{
	if (root * root > n)
		return (-1);
	if (root * root == n)
		return (root);

	return (square_root(n, root + 1));
}

/**
 * _sqrt_recursion -  returns the natural square root of a number
 * @n: number
 * Return: natural square of n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (square_root(n, 0));
}
