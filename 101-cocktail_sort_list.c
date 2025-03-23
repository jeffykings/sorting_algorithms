#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: the doubly linked list to be sorted
 */

 void cocktail_sort_list(listint_t **list)
{
	int swap, i, j, size, counter;

	listint_t *temp = *list;

	if (!temp)
		return;

	swap = 0;
	size = 0;
	counter = 0;

	while (temp)
	{
		temp = temp->next;
		size++;
	}
	temp *list;

	while (swap)
	{
		for (i = counter; i < size - counter; i++)
		{
			if (temp->n > temp->next->n)
			{
				first = temp;
				second temp->next;

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
				swap = 1;
			}
			temp = temp->next;
		}

		if (swap == 0)
			break;
		swap = 0;
		counter++;
		temp = temp->prev;

		for (j = i - counter; j >= 0; j--)
		{
			if (temp->n < temp->prev->n)
			{
				first = temp->prev;
				second temp;

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
				swap = 1;
			}
			temp = temp->prev;
		}
	}
}
