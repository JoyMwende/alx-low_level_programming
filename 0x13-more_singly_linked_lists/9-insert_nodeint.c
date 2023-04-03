#include "lists.h"

/**
 * insert_nodeint_at_index - insert new node
 * @head: linked list head
 * @idx: certain index
 * @n: node
 * Return: address of new node, otherwise NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int g;
	listint_t *node_n;
	listint_t *x;

	x = *head;

	if (idx != 0)
	{
		g = 0;

		while (g < idx - 1 && x != NULL)
		{
			g++;
			x = x->next;
		}
	}

	if (x == NULL && idx != 0)
		return (NULL);

	node_n = malloc(sizeof(listint_t));
	if (node_n == NULL)
		return (NULL);

	node_n->n = n;

	if (idx == 0)
	{
		node_n->next = *head;
		*head = node_n;
	}
	else
	{
		node_n->next = x->next;
		x->next = node_n;
	}

	return (node_n);
}
