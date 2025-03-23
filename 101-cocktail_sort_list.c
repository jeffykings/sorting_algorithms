#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: the doubly linked list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int swap, i, j, size;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	swap = 1;
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	temp = *list;

	while (swap)
	{
		for (i = 1; i <= size - 1; i++)
		{
			if (temp->n > temp->next->n)
			{
				swap_list(list, temp, temp->next);
				swap = 1;
			} else
				temp = temp->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		temp = temp->prev;
		for (j = size - 2; j > 0; j--)
		{
			if (temp->n < temp->prev->n)
			{
				swap_list(list, temp->prev, temp);
				swap = 1;
			} else
				temp = temp->prev;
		}
	}
}

/**
 * swap_list - used to swap a doubly linked list
 *
 * @list: the header pointing to the start of the doubly
 * linked list to be swapped
 * @first: the pointer to the first node to be swapped
 * @second: the pointer to the second node to be swapped
 */

void swap_list(listint_t **list, listint_t *first, listint_t *second)
{
	if (first->prev != NULL)
		first->prev->next = second;
	else
		*list = second;

	if (second->next != NULL)
	second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	print_list(*list);
}
