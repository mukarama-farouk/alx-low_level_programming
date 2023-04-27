#include "lists.h"

/**
 * add_node - function that adds a new node at the
 * beginning of a list_t list.
 * @head: head of the linked list
 * @str: string
 * Return: Address of the head
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_code;
	size_t nchar;

	new_code = malloc(sizeof(list_t));
	if (new_code == NULL)
		return (NULL);
	new_code->str = strdup(str);
	for (nchar = 0; str[nchar]; nchar++)
		;
	new_code->len = nchar;
	new_code->next = *head;
	*head = new_code;

	return (*head);
}
