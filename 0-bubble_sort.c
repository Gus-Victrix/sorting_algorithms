#include "sort.h"

/**
* swap - Swap an element of an array with one after it.
*
* @array: The array to be manipulated.
* @idx: The index of element to be swapped.
*/
void swap(int *array, int idx)
{
	array[idx] ^= array[idx + 1];
	array[idx + 1] ^= array[idx];
	array[idx] ^= array[idx + 1];
}

/**
* bubble_sort - Apply bubble sort algorithm on an integer array.
*
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	int i, j, sorted;

	if (!array || size <= 1)
		return;

	for (i = size - 1; i > 0; i--)
	{
		sorted = 1;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j);
				sorted = 0;
				print_array(array, size);
			}
		}
		if (sorted)
			break;
	}
}
