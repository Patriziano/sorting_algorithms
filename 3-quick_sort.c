#include "sort.h"

/**
 * swap - The fucntion swaps the values in two variables
 * @first: The first varaiable
 * @second: The second variable
 * Return: Nothing
 */

void swap(int *first, int *second)
{
	int tmp = *first;

	*first = *second;
	*second = tmp;
}

/**
 * partition - The function that uses Divide and Conquer to split
 *             an array around a chosen pivot
 * @array: The array of numbers
 * @low: The lowest index
 * @high: The highest index
 * @size: The array size
 * Return: The index of the pivot when it is at its right position
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, idx, j;

	pivot = array[high];
	idx = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			idx++;
			swap(&array[idx], &array[j]);
		}
	}
	swap(&array[idx + 1], &array[high]);
	print_array(array, (size));
	return (idx + 1);
}

/**
 * q_sort - The function that considers the low and high value in an array
 * @array: An array of number
 * @low: The lowest index of an array and sub-arrays
 * @high: The highest index of an array and sub-arrays
 * @size: The array size
 * Return: Nothing
 */

void q_sort(int *array, int low, int high, size_t size)
{
	int part_idx;

	if (low < high)
	{
		part_idx = partition(array, low, high, size);
		q_sort(array, low, part_idx - 1, size);
		q_sort(array, part_idx + 1, high, size);
	}
}

/**
 * quick_sort - The function that sorts an array of integers in
 *              ascending order using the Quick sort algorithm
 * @array: An array of numbers
 * @size: The array size
 * Return: NOthing
 */

void quick_sort(int *array, size_t size)
{
	int high, low;

	if ((size <= 0) || !(array))
		return;

	high = size - 1;

	low = 0;
	q_sort(array, low, high, size);
}
