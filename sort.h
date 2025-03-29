#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recur(int *array, int low, int high, int size);
int partition(int *array, int low, int high, int size);
void swap(int *array, int *first, int *second, int size);
void shell_sort(int *array, size_t size);
void swap_shell(int *first, int *second);
void cocktail_sort_list(listint_t **list);
void swap_list(listint_t **list, listint_t *first, listint_t *second);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *temp_sorted, int lb, int mid, int ub);
void merge_sorter(int *array, int *temp_sorted, int lb, int ub);
void print(int *array, int lb, int ub);
void init_print(int *array, int lb, int mid, int ub);
void heap_sort(int *array, size_t size);
void heap_swap(int *array, int first, int second);
void heapify(int *array, int size, int large, int const_array_size);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counter_radix_sort(int *array, int size, int pos);
void bitonic_sort(int *array, size_t size);
void bitonic_sorter(int *array, int low, int high, int direction);
void bitonic_merge(int *array, int low, int high, int direction);
void bitonic_swap(int *first, int *second);
void quick_sort_hoare(int *array, size_t size);
void quick_sorter_hoare(int *array, int lb, int ub, int size);
int hoare_partition(int *array, int lb, int ub, int size);
void hoare_swap(int *first, int *end);

#endif
