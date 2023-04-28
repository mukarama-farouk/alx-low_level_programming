#include "lists.h"

/**
 * free_list -  function that frees a list_t list.
 * @head: head of list
 * Return: no return
 */
void free_list(list_t *head)
{
	list_t *node;

	while ((node = head) != NULL)
	{
		head = head->next;
		free(node->str);
		free(node);
	}
}
