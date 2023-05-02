#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: Head of a list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevNode = NULL;
	listint_t *nextNode = NULL;

	while (*head)
	{
		nextNode = (*head)->next;
		(*head)->next = prevNode;
		prevNode = *head;
		*head = nextNode;
	}
	*head = prevNode;
	return (*head);
}
