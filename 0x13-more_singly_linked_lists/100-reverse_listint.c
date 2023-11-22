#include "lists.h"

/**
 * reverse_listint - reverses a linked list.
 * @head: pointer to the head of a list.
 *
 * Return: pointer to the first node after reversal.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = NULL;
	listint_t *next = NULL;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

