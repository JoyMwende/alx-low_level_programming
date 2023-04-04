#include "lists.h"

/**
 * find_listint_loop - find loop in linked list
 * @head: listint head
 * Return: address of the node where loop starts
 * or NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a2;
	listint_t *x;

	a2 = head;
	x = head;
	while (head && a2 && a2->next)
	{
		head = head->next;
		a2 = a2->next->next;

		if (head == a2)
		{
			head = x;
			x = a2;
			while (1)
			{
				a2 = x;
				while (a2->next != head && a2->next != x)
				{
					a2 = a2->next;
				}

				if (a2->next == head)
					break;

				head = head->next;
			}
			return (a2->next);
		}
	}

	return (NULL);
}
