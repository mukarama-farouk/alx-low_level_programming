#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new list at a given index
 * @head: head of list
 * @idx: Index of list
 * @n: integer
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *newNode;
	listint_t *ptr = *head;

	if (idx != 0)
	{
		for ( i = 0; i < idx - 1 && ptr != NULL; i++)
			ptr = ptr->next;
	}

	if (ptr == NULL && idx != 0)
		return (NULL);
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	return (newNode);
}
