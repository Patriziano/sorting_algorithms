#include "sort.h"
void swap(int *first, int *second)
{
	int tmp = *first;

	*first = *second;
	*second = tmp;
}

int partition(int *array, int low, int high)
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
	return (idx + 1);
}

void q_sort(int *array, int low, int high)
{
	int part_idx;

	if (low < high)
	{
		part_idx = partition(array, low, high);
		q_sort(array, low, part_idx - 1);
		q_sort(array, part_idx + 1, high);
		if (low == 0)
		{
			printf("from inside swap: ");
			print_array(array, (high + 1));
		}
	}
}



void quick_sort(int *array, size_t size)
{
	int high, low;

	if ((size <= 0) || !(array))
		return;

	high = size - 1;

	low = 0;
	q_sort(array, low, high);
}
