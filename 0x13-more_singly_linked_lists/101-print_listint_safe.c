#include "lists.h"

/**
 * free_listp - free linked list
 * @head: list head
 * Return: no return
 */

void free_listp(listp_t **head)
{
	listp_t *x;
	listp_t *y;

	if (head != NULL)
	{
		y = *head;
		while ((x = y) != NULL)
		{
			y = y->next;
			free(x);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - print linked list listint_t
 * @head: listint_t  list head
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t xnodes = 0;
	listp_t *np, *nw, *a;

	np = NULL;
	while (head != NULL)
	{
		nw = malloc(sizeof(listp_t));

		if (nw == NULL)
			exit(98);

		nw->p = (void *)head;
		nw->next = np;
		np = nw;

		a = np;

		while (a->next != NULL)
		{
			a = a->next;
			if (head == a->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&np);
				return (xnodes);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		xnodes++;
	}

	free_listp(&np);
	return (xnodes);
}
