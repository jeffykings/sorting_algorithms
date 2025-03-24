#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t *count, *temp_sorted, i, max;
	int j;

	if (array == NULL || size < 2)
		return;

	j = array[0];
	for (i = 1; i < size; i++)
	{
		if (j < array[i])
			j = array[i];
	}
	max = j;
	count = calloc(max + 1, sizeof(size_t));
	if (count == NULL)
		return;
	for (i = 0; i < size; i++)
		++count[array[i]];
	printf("%lu, ", count[0]);
	for (i = 1; i <= max; i++)
	{
		count[i] = count[i] + count[i - 1];
		printf("%lu", count[i]);
		if (i != max)
			printf(", ");
	}
	printf("\n");
	temp_sorted = calloc(size, sizeof(size_t));
	if (temp_sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = size; i > 0; i--)
		temp_sorted[--count[array[i - 1]]] = array[i - 1];
	for (i = 0; i < size; i++)
		array[i] = temp_sorted[i];

	free(temp_sorted);
	free(count);
}
