#include "sort.h"

/**
 * swap - The fucntion swaps two integers
 * @min_value: The minimum value
 * @idx: The value at the left-most position to swap
 * Return: Nothing
 */

void swap(int *min_value, int *idx)
{
	int tmp = *min_value;

	*min_value = *idx;
	*idx = tmp;
}


/**
 * selection_sort - The function sorts an array using selection sorting
 * @array: An array
 * @size: The size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, min_value, post;

	if (array == NULL || size <= 0)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		min_value = idx;
		post = idx + 1;
		for (post = idx + 1; post < size; post++)
		{
			if (array[post] < array[min_value])
				min_value = post;
		}
		if (min_value != idx)
		{
			swap(&array[min_value], &array[idx]);
			print_array(array, size);
		}

	}
}
