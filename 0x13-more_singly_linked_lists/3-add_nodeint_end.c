#include "lists.h"

/**
 * add_nodeint_end - add a new node at the
 * end of listint_t list
 * @head: head of listint_t list
 * @n: the new node
 * Return: the address of the new element
 * return NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end_node;
	listint_t *k;

	(void)k;

	end_node = malloc(sizeof(listint_t));

	if (end_node == NULL)
		return (NULL);

	end_node->n = n;
	end_node->next = NULL;
	k = *head;
	if (*head == NULL)
	{
		*head = end_node;
	}
	else
	{
		while (k->next != NULL)
			k = k->next;
		k->next = end_node;
	}

	return (*head);
}
