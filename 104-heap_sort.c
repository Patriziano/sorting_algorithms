#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: The array.
 * @first: Index of the first integer.
 * @second: Index of the second integer.
 */
void swap(int *array, int first, int second)
{
	int temp;

	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}

/**
 * sift_down - Helper function to perform the sift-down operation in a heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @start: The index to start the sift-down operation.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap_idx = root;

		if (array[swap_idx] < array[child])
		swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
		swap_idx = child + 1;
		if (swap_idx == root)
		return;

		swap(array, root, swap_idx);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, end;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
	sift_down(array, size, i, size - 1);

	for (end = size - 1; end > 0; end--)
	{
		swap(array, 0, end);
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
