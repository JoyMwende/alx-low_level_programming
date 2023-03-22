#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array
 * @size: number of elements in the array
 * @cmp: function pointer
 * Return: index of the first element when
 * cmp does not return 0
 * return -1 if no element matches of if size <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);

		for (x = 0; x < size; x++)
		{
			if (cmp(array[x]))
				return (x);
		}
	}

	return (-1);
}
