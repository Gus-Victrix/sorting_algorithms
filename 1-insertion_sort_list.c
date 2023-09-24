#include "sort.h"

/**
* swap - Swap nodes of a doubly linked list
*
* @current: The current node
* @prev: The previous node
* @list: The pointer to the linked list
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
* insertion_sort_list - Sort a doubly linked list by comparing each
* elem with the previous
*
* @list: The linked list to sort
*
* Return: Anything, cause void function
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *browse = NULL;

	if (!list || !*list)
		return;

	browse = (*list)->next;
	while (browse)
	{
		while (browse->prev && browse->prev->n > browse->n)
		{
			swap(browse, browse->prev, list);
			print_list(*list);
		}
		browse = browse->next;
	}
}
