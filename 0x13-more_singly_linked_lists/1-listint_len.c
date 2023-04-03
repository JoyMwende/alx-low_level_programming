#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: the linked list
 * Return: the number of elements in listint_t list
 */

size_t listint_len(const listint_t *h)
{
	size_t element = 0;

	while (h != NULL)
	{
		h = h->next;
		element++;
	}

	return (element);
}
