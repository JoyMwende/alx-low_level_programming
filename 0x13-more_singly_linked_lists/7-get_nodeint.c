#include "lists.h"

/**
 * get_nodeint_at_index - return nth node of listint_t list
 * @head: listint_t head
 * @index: node position
 * Return: nth node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int f = 0;

	while (f < index && head != NULL)
	{
		f++;
		head = head->next;
	}
	return (head);
}
