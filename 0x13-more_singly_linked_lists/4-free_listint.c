#include "lists.h"

/**
 * free_listint - frees a list
 * @head: head of listint_t
 * Return: no return
 */

void free_listint(listint_t *head)
{
	listint_t *list;

	while ((list = head) != NULL)
	{
		head = head->next;
		free(list);
	}
}
