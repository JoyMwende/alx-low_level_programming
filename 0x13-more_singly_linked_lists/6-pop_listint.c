#include "lists.h"

/**
 * pop_listint - delete listint_t head node
 * @head: head of listint
 * Return: data of head node n
 */

int pop_listint(listint_t **head)
{
	int head_node;
	listint_t *s;
	listint_t *d;

	if (*head == NULL)
		return (0);

	d = *head;

	head_node = d->n;

	s = d->next;

	free(d);

	*head = s;

	return (head_node);
}
