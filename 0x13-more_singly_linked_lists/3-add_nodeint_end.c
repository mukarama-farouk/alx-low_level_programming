#include "lists.h"

/**
 * add_nodeint_end - Adds node at the end of a list
 * @head: pointer of the list
 * @n: data to insert in the new node
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode;
	listint_t *ptr = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
	return (newNode);
}
