#include "lists.h"

/**
 * free_listp2 - frees list listint_t
 * @head: list head
 * Return: no return
 */

void free_listp2(listp_t **head)
{
	listp_t *d;
	listp_t *e;

	if (head != NULL)
	{
		e = *head;
		while ((d = e) != NULL)
		{
			e = e->next;
			free(d);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - frees listint_t
 * @h: list head
 * Return: size of free'd list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t ynodes = 0;
	listp_t *hp, *nw, *ad;
	listint_t *crt;

	hp = NULL;
	while (*h != NULL)
	{
		nw = malloc(sizeof(listp_t));

		if (nw == NULL)
			exit(98);

		nw->p = (void *)*h;
		nw->next = hp;
		hp = nw;

		ad = hp;

		while (ad->next != NULL)
		{
			ad = ad->next;
			if (*h == ad->p)
			{
				*h = NULL;
				free_listp2(&hp);
				return (ynodes);
			}
		}

		crt = *h;
		*h = (*h)->next;
		free(crt);
		ynodes++;
	}

	*h = NULL;
	free_listp2(&hp);
	return (ynodes);
}
