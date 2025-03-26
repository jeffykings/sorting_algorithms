#include "sort.h"

/**
 * radix_sort -  sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (array == NULL && size < 2)
		return;

	max = get_max(array, size);

	for (pos = 1; max / pos > 0; pos = 10 * pos)
	{
		counter_radix_sort(array, size, pos);
		print_array(array, size);
	}
}

/**
 * get_max - checks for the maximum value in the list
 *
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: the maximum element
 */

int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * counter_radix_sort - uses counter sort to solve for radix sort
 *
 * @array: the array we are sorting
 * @size: the size of the array
 * @pos: the significant digit we are on and this algorithm uses
 * least significant digit implementation LSD
 */

void counter_radix_sort(int *array, int size, int pos)
{
	int i, *counter, *temp_sorted;

	counter = calloc(10, sizeof(int));
	if (counter == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		++counter[(array[i] / pos) % 10];
	}

	for (i = 1; i < 10; i++)
		counter[i]  += counter[i - 1];

	temp_sorted = calloc(size, sizeof(int));
	if (temp_sorted == NULL)
	{
		free(counter);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		temp_sorted[--counter[(array[i] / pos) % 10]] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = temp_sorted[i];
	}

	free(counter);
	free(temp_sorted);
}
