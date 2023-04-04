#include "lists.h"

/**
 * reverse_listint - reverses linked list listint_t
 * @head: listint_t head
 * Return: pointer to the first node of
 * the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *t;
	listint_t *u;

	t = NULL;
	u = NULL;

	while (*head != NULL)
	{
		u = (*head)->next;
		(*head)->next = t;
		t = *head;
		*head = u;
	}

	*head = t;
	return (*head);
}
