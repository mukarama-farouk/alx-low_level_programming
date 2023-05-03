#include "lists.h"

/**
 * print_listint_safe - prints a link list
 * @head: head of list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
       	const listint_t *current = head;
	size_t node = 0;

	while (current != NULL)
	{
		printf("[%p]%d\n", (void *)current, current->n);
		node++;

		if (current <= current->next)
			exit (98);
		current = current->next;
	}
	return (node);
}
