#include "sort.h"

/**
 * selection_sort - Sorts array via selection sort algorithm.
 *
 * @array: Integer array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	elem_t tracker;

	if (!array || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tracker.n = array[i];
		tracker.index = i;

		for (j = i; j < size; j++)
		{
			if (array[j] < tracker.n)
			{
				tracker.n = array[j];
				tracker.index = j;
			}
		}
		if (tracker.index != i)
		{
			array[tracker.index] = array[i];
			array[i] = tracker.n;
			print_array(array, size);
		}
	}
}
