#include "main.h"

/**
 * prime_number - determine if n is prime number
 * @n: first number
 * @i: second number
 * Return: 1 if n is prime number, otherwise 0
 */

int prime_number(int n, int i)
{
	if (i == n)
		return (1);
	if (n % i == 0)
		return (0);

	return (prime_number(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise return 0
 * @n: input integer
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (prime_number(n, 2));
}
