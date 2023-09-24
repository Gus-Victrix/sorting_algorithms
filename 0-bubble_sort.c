#include "sort.h"

/**
 * bubble_sort - Performs a bubble sort on an array in ascending order.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, newn = 0;
	char sorted = 1;

	if (!array || size <= 1)
		return;
	n = size;
	while (sorted)
	{
		sorted = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i] < array[i - 1])
			{
				array[i] ^= array[i - 1];
				array[i - 1] ^= array[i];
				array[i] ^= array[i - 1];
				sorted = 1;
				newn = i;
				print_array(array, size);
			}
		}
		n = newn;
	}
}
