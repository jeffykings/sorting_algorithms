#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (array != NULL && size > 2)
		merge_sorter(array, 0, size - 1);
}

/**
 * merge_sorter - implements the merge_sort
 *
 * @array: the array to be sorted
 * @lb: the lower bound of a particular half
 * @ub: the upper bound of a particular half
 */

void merge_sorter(int *array, int lb, int ub)
{
	int mid;

	if (lb < ub)
	{
		/**
		 * for the size of the left array be <= the size of the right array.
		 * i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
		 */

		mid = lb + (ub - lb + 1) / 2 - 1;

		/**
		 * but for the size fo right array to be <= the size of the right array
		 * mid = (ub + lb) / 2
		 */

		merge_sorter(array, lb, mid);
		merge_sorter(array, mid + 1, ub);
		merge(array, lb, mid, ub);
	}
}

/**
 * merge - merges the sorted cells
 *
 * @array: the array to be sorted
 * @lb: the lower bound of a particular half
 * @mid: the middle of a particular half
 * @ub: the upper bound of a particular half
 */

void merge(int *array, int lb, int mid, int ub)
{
	int *temp_sorted, i, j, k;

	temp_sorted = malloc((ub + 1) * sizeof(int));
	if (temp_sorted == NULL)
		return;
	init_print(array, lb, mid, ub);
	i = k = lb;
	j = mid + 1;
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{ temp_sorted[k] = array[i];
			i++;
		} else
		{
			temp_sorted[k] = array[j];
			j++;
		} k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{ temp_sorted[k] = array[j];
			j++;
			k++;
		}
	} else
	{
		while (i <= mid)
		{
			temp_sorted[k] = array[i];
			i++;
			k++;
		}
	}
	printf("[Done]: ");
	print(temp_sorted, lb, ub);
	for (i = lb; i <= ub; i++)
		array[i] = temp_sorted[i];
	free(temp_sorted);
}

/**
 * print - prints array
 *
 * @array: the array to be sorted
 * @lb: the lower bound of a particular half
 * @ub: the upper bound of a particular half
 */

void print(int *array, int lb, int ub)
{
	int i;

	for (i = lb; i <= ub; i++)
	{
		printf("%d", array[i]);
		if (i != ub)
			printf(", ");
	}
	printf("\n");
}

/**
 * init_print - prints the initial arrays to be merged
 *
 * @array: the array to be sorted
 * @lb: the lower bound of a particular half
 * @mid: the middle of a particular half
 * @ub: the upper bound of a particular half
 */

void init_print(int *array, int lb, int mid, int ub)
{
	printf("Merging...\n");
	printf("[left]: ");
	print(array, lb, mid);
	printf("[right]: ");
	print(array, mid + 1, ub);
}
