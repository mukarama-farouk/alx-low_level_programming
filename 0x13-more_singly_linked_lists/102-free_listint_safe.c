#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: head of the list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size;
	listint_t *cur;
	listint_t *next;

	size = 0;
	if (h == NULL)
	{
		return (0);
	}
	cur = *h;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
		size++;
	}
	*h = NULL;
	return (size);
}
