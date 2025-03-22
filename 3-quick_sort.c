#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm using Lomuto partition scheme
 *
 * @array: the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recur(array, 0, size - 1, size);
}

/**
 * quick_sort_recur - recurrsively calls each partition
 *
 * @array: array to be recurrsively called
 * @low: the smallest index in any partition
 * @high: the highest partition in any partition
 */

void quick_sort_recur(int *array, int low, int high, int size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recur(array, 0, pivot_index - 1, size);
		quick_sort_recur(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - partitions the array using Lomuto scheme ie the highest index
 * 
 * @array: array to be recurrsively called
 * @low: the smallest index in any partition
 * @high: the highest partition in any partition
 *
 * Return: the index of the pivot element always
 */

int partition(int *array, int low, int high, int size)
{
	int pivot_index, i, j;

	pivot_index = high;
	i = low;

	for (j = i; j <= high; j++)
	{
		if (array[j] < array[high])
		{
			swap(array, &array[j], &array[i], size);
			i++;
		}
	}
	swap(array, &array[i], &array[pivot_index], size);
	return (i);
}

/**
 * swap - swaps to element in different postions
 *
 * @first: the pointer to the first element to be swapped
 * @second: the pointer to the second element to be swapped
 */

void swap(int *array, int *first, int *second, int size)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
	if (second != first)
		print_array(array, size);
}
