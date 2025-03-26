#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i, large;

	if (array == NULL || size < 1)
		return;

	large = (size / 2) - 1;
	for (i = large; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		heap_swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - this used to convert the array to heap using sift-down
 * or max-heap method
 *
 * @array: the array working on
 * @size: the size of the array we are working on at a particular time
 * @large: the first node aftera heap or the starting parenting
 * @const_array_size:  the actual length of the full array. it is here
 * so i can print the full array after each swap
 */

void heapify(int *array, int size, int large, int const_array_size)
{
	int i, left_element, right_element;

	i = large;
	left_element = (2 * large) + 1;
	right_element = (2 * large) + 2;

	if (left_element < size && array[large] < array[left_element])
	{
		large = left_element;
	}

	if (right_element < size && array[large] < array[right_element])
	{
		large = right_element;
	}

	if (large != i)
	{
		heap_swap(array, i, large);
		print_array(array, const_array_size);
		heapify(array, size, large, const_array_size);
	}
}

/**
 * heap_swap - used to swap two elements
 *
 * @array: the array to be swapped
 * @first: the first element to be swapped
 * @second: the second element to be swapped
 */

void heap_swap(int *array, int first, int second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
