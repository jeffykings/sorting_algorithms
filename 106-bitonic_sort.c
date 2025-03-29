#include "sort.h"

void bitonic_sort(int *array, size_t size)
{
	bitonic_sorter(array, 0, size - 1, 1);
}

void bitonic_sorter(int *array, int low, int high, int direction)
{
	if (high > 1)
	{
		k = (high  + 1 - low) / 2;

		bitonic_sorter(array, low, k - 1, 1);
		bitonic_sorter(array, k, high - low, 0);
		bitonic_merge(array, low, high + 1, direction);
	}
}

void bitonic_merge(int *array, int low, int high, int direction)
{
	int i;

	if (high > 1)
	{
		distance = (high - low)  / 2;

		for (i = low;  i < low + distance; i++)
		{
			if (direction == (array[i] > array[i + distance]))
			{
				bitonic_swap(array[i], array[i + distance]);
			}
		}
		
		bitonic_merge(array, low, distance, direction);
		bitonic_merge(array, distance, high - low, direction);
	}
}
