#include "lists.h"

/**
 * add_node_end - function that adds a new node at the
 * end of a list_t list.
 * @head: head of list
 * @str: string
 * Return: the address of the new element,
 * or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_code;
	list_t *end;
	size_t nchar;

	new_code = malloc(sizeof(list_t));
	if (new_code == NULL)
		return (NULL);

	new_code->str = strdup(str);

	for (nchar = 0; str[nchar]; nchar++)
		;

	new_code->len = nchar;
	new_code->next = NULL;
	end = *head;

	if (end == NULL)
	{
		*head = new_code;
	}
	else
	{
		while (end->next != NULL)
			end = end->next;
		end->next = new_code;
	}

	return (*head);
}
