#include "sort.h"

/**
* swap - Swap array elements.
*
* @array: The array to be manipulated.
* @idx1: The first index.
* @idx2: The second index.
*/
void swap(int *array, int idx1, int idx2)
{

	array[idx2] ^= array[idx1];
	array[idx1] ^= array[idx2];
	array[idx2] ^= array[idx1];
}

/**
* shell_sort - Shell sort an array using the Knuth sequence.
*
* @array: Array to sort.
* @size: Size of the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int j, k;

	if (!array || size <= 1)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			k = array[i];
			j = i - gap;
			while (j >= 0 && k < array[j])
			{
				array[j + gap] = array[j];
				j -= gap;
			}
			array[j + gap] = k;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
