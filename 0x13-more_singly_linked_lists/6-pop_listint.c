#include "lists.h"

/**
 * pop_listint - deletes a lists
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int num;
	listint_t *ptr;

	if (!(head && *head))
		return (0);

	num = (*head)->n;
	ptr = (*head)->next;
	free(*head);
	*head = ptr;
	return (num);
}
