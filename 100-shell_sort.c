#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using shell sort
 *@array:  The array to be sorted
 *@size: size of the array
 *Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int insertion_value;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			insertion_value = array[i];
			j = i;

			while (j >= gap && array[j - gap] > insertion_value)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}

				array[j] = insertion_value;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
