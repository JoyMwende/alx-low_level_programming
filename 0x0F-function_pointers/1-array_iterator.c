#include "function_pointers.h"

/**
 * array_iterator - executes a function on each array element
 * @array: array
 * @size: size of the array
 * @action: pointer to the function
 * Return: no return
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int w;

	if (array && action)
		for (w = 0; w < size; w++)
			action(array[w]);
}
