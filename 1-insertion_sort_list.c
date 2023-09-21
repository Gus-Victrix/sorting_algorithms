#include "sort.h"

/**
 * insertion_sort_list - Applies the insertion sort algorithm to sort a list.
 *
 * @list: List of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *traverse;
	char moved = 0;

	current = (*list)->next;
	while (current)
	{
		traverse = current->next;
		temp = current->prev;
		moved = 0;
		while (temp->prev != NULL && temp->n > current->n)
		{
			temp = temp->prev;
			moved = 1;
		}
		if (moved)
		{
			if (current->next)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			if (temp->prev == NULL)
			{
				temp->prev = current;
				current->next = temp;
				current->prev = NULL;
				*list = current;
			}
			else
			{
				current->prev = temp;
				current->next = temp->next;
				temp->next->prev = current;
				temp->next = current;
			}
		}
		current = traverse;
		print_list(*list);
	}
}
