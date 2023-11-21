#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: Head of the list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current_node;

	while ((current_node = head) != NULL)
	{
		head = head->next;
		free(current_node);
	}
}

