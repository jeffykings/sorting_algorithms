#include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, j;
	int i;

	gap = 1;

	/*generating Knuth sequence*/
	while (gap < size / 3)
		gap = 3 * gap + 1;

	for (; gap >= 1; gap = gap / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i] < array[i + gap])
					break;

				swap_shell(&array[i], &array[i + gap]);
			}
		}
		print_array(array, size);
	}
}

/**
 * swap_shell - swaps to element in different postions
 *
 * @first: the pointer to the first element to be swapped
 * @second: the pointer to the second element to be swapped
 */

void swap_shell(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
