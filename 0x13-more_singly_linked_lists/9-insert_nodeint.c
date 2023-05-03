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

	newNode = malloc(sizeof(listint_t));
	if (!(newNode && head))
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}
	for (i = 0; ptr && i < idx; i++)
	{
		if (i == idx - 1)
		{
			newNode->next = ptr->next;
			ptr->next = newNode;
			return (NULL);
		}
		else
			ptr = ptr->next;
	}
	return (NULL);
}
