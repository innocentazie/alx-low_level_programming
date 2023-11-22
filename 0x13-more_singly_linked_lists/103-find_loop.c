#include "lists.h"

/**
 * find_listint_loop - finds the start of a loop in a linked list.
 * @head: pointer to the head of a list.
 *
 * Return: the address of the node where the loop starts, NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr;
	listint_t *fast_ptr;

	slow_ptr = head;
	fast_ptr = head;

	while (head && fast_ptr && fast_ptr->next)
	{
		head = head->next;
		fast_ptr = fast_ptr->next->next;

		if (head == fast_ptr)
		{
			head = slow_ptr;

			while (1)
			{
				fast_ptr = head;
				while (fast_ptr->next != head && fast_ptr->next != slow_ptr)
				{
					fast_ptr = fast_ptr->next;
				}
				if (fast_ptr->next == head)
					break;

				slow_ptr = slow_ptr->next;
			}
			return (fast_ptr->next);
		}
	}

	return (NULL);
}

