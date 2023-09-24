#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int array[] = {982, 7732, 3083, 803, 2541, 2540, 8461, 8103, 7353, 5723, 8005, 6719, 5631, 1470, 949, 358, 8507, 7930, 4099, 6886};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
