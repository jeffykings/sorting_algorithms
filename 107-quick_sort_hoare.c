#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array array to be sorted
 * @size: size of the array to be sorted
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	 quick_sorter_hoare(array, 0, size - 1, size);
}

/**
 * quick_sorter_hoare - it recurssively calls it self
 *
 * @array: the array to be sorted
 * @lb: the lowest index in the array
 * @ub: the largest index in the array
 * @size: the size of the array
 */

void quick_sorter_hoare(int *array, int lb, int ub, int size)
{
	int pivot;

	if (lb < ub)
	{
		pivot = hoare_partition(array, lb, ub, size);
		quick_sorter_hoare(array, lb, pivot - 1, size);
		quick_sorter_hoare(array, pivot, ub, size);
	}
}

/**
 * hoare_partition - partitions the algorithm
 * @array: the array to be sorted
 * @lb: the lowest element
 * @ub: the highest element
 * @size: the size of the element
 *
 * Return: the pivot of the element
 */

int hoare_partition(int *array, int lb, int ub, int size)
{
	int first, end, pivot;

	first = lb - 1;
	end = ub + 1;
	pivot = array[ub];

	while (first < end)
	{
		do {
			first++;
		} while (array[first] < pivot);

		do {
			end--;
		} while (array[end] > pivot);

		if (first < end)
		{
			hoare_swap(&array[first], &array[end]);
			print_array(array, size);
		}
	}
	return (first);

}

/**
 * hoare_swap - swaps to elements
 *
 * @first: the first element to be swapped
 * @end: the second element to be swapped
 */

void hoare_swap(int *first, int *end)
{
	int temp;

	temp = *first;
	*first = *end;
	*end = temp;
}
