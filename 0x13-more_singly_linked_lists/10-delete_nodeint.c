#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index
 * @head: linked list head
 * @index: index of node to be deleted
 * Return: 1 if it succeeded
 * -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int d;
	listint_t *node_prev;
	listint_t *next;

	node_prev = *head;

	if (index != 0)
	{
		d = 0;
		while (d < index - 1 && node_prev != NULL)
		{
			d++;
			node_prev = node_prev->next;
		}
	}

	if (node_prev == NULL || (node_prev->next == NULL && index != 0))
	{
		return (-1);
	}

	next = node_prev->next;

	if (index != 0)
	{
		node_prev->next = next->next;
		free(next);
	}
	else
	{
		free(node_prev);
		*head = next;
	}

	return (1);
}
