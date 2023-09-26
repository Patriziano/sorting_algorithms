#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t input;
	int *counting_array = 0, i, max_value, *output;
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array to determine the array size*/
	max_value = array[0];
	for (input = 1; input < size; input++)
	{
		if (array[input] > max_value)
		max_value = array[input];
	}

	/* Create a counting array and initialize it with zeros. */
	counting_array = malloc((max_value + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max_value; i++)
	{
		counting_array[i] = 0;
	}

	/* Count the occurrences of each element in the original array. */
	for (input = 0; input < size; input++)
	{
		counting_array[array[input]]++;
	}

	/* Update the counting array to store the cumulative count of elements. */
	for (i = 1; i <= max_value; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}
	print_array(counting_array, max_value + 1);
	/* Create a temporary output array. */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(counting_array);
			return;
	}

	/* Build the sorted output array using the counting array. */
	for (i = size - 1; i >= 0; i--)
	{
		output[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy the sorted output array back to the original array. */
	for (input = 0; input < size; input++)
	{
		array[input] = output[input];
	}

/*	for (i = 0; i <= max_value; i++)
	{
		printf("%d", counting_array[i]);
		if (i <= max_value)
			printf(", ");
	}
	printf("\n");
*/
	/* Free dynamically allocated memory. */
	free(counting_array);
	free(output);
}
