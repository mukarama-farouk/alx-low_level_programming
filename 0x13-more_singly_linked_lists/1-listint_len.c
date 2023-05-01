#include "lists.h"

/**
 * listint_len - Function that returns the number of elements in a list
 * @h: Pointer of list
 *
 * Return: Number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t all_nodes = 0;

	while (h != NULL)
	{
		all_nodes++;
		h = h->next;
	}
	return (all_nodes);
}
