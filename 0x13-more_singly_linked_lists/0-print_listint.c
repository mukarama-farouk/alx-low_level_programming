#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Prints all the elements
 * @h: pointer of list
 *
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t all_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		all_nodes++;
		h = h->next;
	}
	return (all_nodes++);
}
