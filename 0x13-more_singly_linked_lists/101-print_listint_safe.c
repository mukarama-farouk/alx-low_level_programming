#include "lists.h"



/**
 * print_listint_safe - prints a link list
 * @head: head of list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *current = head;
