#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	int array[] = {1};
	size_t n = sizeof(array) / sizeof(array[0]);/* 1 */

	print_array(array, n);
	printf("\n");
	merge_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
