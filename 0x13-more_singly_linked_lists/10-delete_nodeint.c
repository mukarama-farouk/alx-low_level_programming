#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at the index
 * @head: head of list
 * @index: Index of the node that should be deleted
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp = *head;
	listint_t *ptr;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);
	ptr = temp->next->next;
	free(temp->next);
	temp->next = ptr;
	return (1);
}
