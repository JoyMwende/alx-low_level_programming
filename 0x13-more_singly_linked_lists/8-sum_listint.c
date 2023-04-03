#include "lists.h"

/**
 * sum_listint - return sum of all data of linked list
 * @head: listint_t head
 * Return: sum
 */

int sum_listint(listint_t *head)
{
	int data_sum = 0;

	while (head != NULL)
	{
		data_sum += head->n;
		head = head->next;
	}

	return (data_sum);
}
