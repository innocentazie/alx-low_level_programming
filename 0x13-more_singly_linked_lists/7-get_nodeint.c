#include "lists.h"

/**
 * get_nodeint_at_index - retrieves the nth node of a linked list
 * @head: pointer to the head of a list
 * @index: index of the desired node
 *
 * Return: the nth node; if node does not exist, returns NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	for (j = 0; head != NULL && j < index; j++)
	{
		head = head->next;
	}

	return (head);
}

