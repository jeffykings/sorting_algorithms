#include "sort.h"

/**
 * bubble_sort - works by repeatedly swapping the adjacent
 * elements if they are in the wrong order
 *
 * @array: the array to be sorted
 * @size: the length of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap, temp;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j]  >  array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}

		if (swap == 0)
			break;
	}
}
