#include "sort.h"

/**
* swap - Swap nodes of a double linked list.
*
* @current: The current node.
* @prev: The previous node.
* @list: The linked list.
*/
void swap(listint_t *current, listint_t *prev, listint_t **list)
{
	listint_t *tmp;

	tmp = prev->prev;
	if (tmp)
		tmp->next = current;
	else
		*list = current;

	current->prev = tmp;

	prev->prev = current;
	prev->next = current->next;
	current->next = prev;
	if (prev->next)
		prev->next->prev = prev;
	else
		prev->next = NULL;
}

/**
* cocktail_sort_list - Sort a linked list using the cocktail shaker.
*
* @list: The linked list to be sorted.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *browse = NULL, *start = NULL, *end = NULL;
	int swaped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	browse = *list;
	while (swaped)
	{
		swaped = 0;
		while (browse->next && browse != end)
		{
			if (browse->n > browse->next->n)
			{
				swap(browse->next, browse, list);
				print_list(*list);
				swaped = 1;
				browse = browse->prev;
			}
			browse = browse->next;
		}
		end = browse->prev;
		browse = end;
		while (browse->prev && browse != start)
		{
			if (browse->n < browse->prev->n)
			{
				swap(browse, browse->prev, list);
				print_list(*list);
				swaped = 1;
				browse = browse->next;
			}
			browse = browse->prev;
		}
		start = browse->next;
		browse = start;
	}
}
