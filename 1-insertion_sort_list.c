#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Description: Swaps nodes themselves, does not modify n values.
 *              Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			/* Detach tmp from its current position */
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			/* Insert tmp before tmp->prev */
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			tmp->next->prev = tmp;

			print_list(*list);
		}
	}
}
