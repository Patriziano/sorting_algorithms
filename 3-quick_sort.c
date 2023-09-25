#include "sort.h"

/**
 * swap - The function that swaps two numbers
 * @first: the first number
 * @second: the second number
 * Return: Nothing
 */

void swap(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}


/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: The index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * lomuto_quick_sort - Recursive function to perform Quick Sort using Lomuto.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	int pivotIndex;

	if (low < high)
	{
		pivotIndex = lomuto_partition(array, low, high, size);
		lomuto_quick_sort(array, low, pivotIndex - 1, size);
		lomuto_quick_sort(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	lomuto_quick_sort(array, low, high, size);
}
