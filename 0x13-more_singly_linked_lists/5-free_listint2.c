#include "lists.h"

/**
 * free_listint2 - frees a list listint
 * @head: head of listint_t
 * Return: no return
 */

void free_listint2(listint_t **head)
{
	listint_t *list;
	listint_t *x;

	if (head != NULL)
	{
		x = *head;
		while ((list = x) != NULL)
		{
			x = x->next;
			free(list);
		}
		*head = NULL;
	}
}
