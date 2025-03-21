#include "sort.h"

/**
 * insertion_sort_list -  that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: the singly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	int swap;
	listint_t *first, *second;

	listint_t *temp = *list;

	while (temp)
	{
		swap = 0;
		first = temp;
		second = temp->next;
		for (; second != NULL && first != NULL && first->n > second->n;)
		{
			if (first->prev != NULL)
				first->prev->next = second;
			if (second->next != NULL)
				second->next->prev = first;
			
			first->next = second->next;
			second->prev = first->prev;
			first->prev = second;
			second->next = first;
			first = second->prev;
			swap = 1;
			print_list(*list);
		}
	}

		if (swap == 0)
			temp = temp->next;
}
