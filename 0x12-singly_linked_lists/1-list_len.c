#include "lists.h"

/**
 * list_len -  a function that returns the number of elements
 * in a linked list_t list
 * @h: singly linked list
 * Return: the number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t all_ele;

	while (h != NULL)
	{
		h = h->next;
		all_ele++;
	}
	return (all_ele);
}
