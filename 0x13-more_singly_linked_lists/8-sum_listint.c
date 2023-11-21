#include "lists.h"

/**
 * sum_listint - calculates the sum of all 'n' data in a linked list
 * @head: pointer to the head of a list
 *
 * Return: sum of all the 'n' data
 */
int sum_listint(listint_t *head)
{
	int total_sum = 0;

	while (head != NULL)
	{
		total_sum += head->n;
		head = head->next;
	}

	return (total_sum);
}

