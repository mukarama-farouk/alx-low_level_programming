#include "lists.h"

/**
 * find_listint_loop - A func that finds a lops in a linked list
 * @head: head of list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tor = head;
	listint_t *hare = head;

	while (tor != NULL && hare != NULL && hare->next != NULL)
	{
		tor = tor->next;
		hare = hare->next->next;

		if (tor == hare)
			return (hare->next);
	}
	return (NULL);
}
