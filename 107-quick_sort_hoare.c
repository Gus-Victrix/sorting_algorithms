#include "sort.h"

/**
 * _swap - Swap two elements of an array.
 *
 * @a: The first index.
 * @b: The second index.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Create a partion of the list, sort it using a pivot.
 *
 * @arr: The array to sort.
 * @low: The index of the first element of the array.
 * @high: The index of the last element of the array.
 * @size: The size of the larger array.
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low, j = high;

	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
		{
			_swap(&arr[i], &arr[j]);
			print_array(arr, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}

/**
 * quickSort - Sort an array using Quick sort algorithm.
 *
 * @arr: The array to sort.
 * @low: The index of the first element of the array.
 * @high: The last element of the array.
 * @size: The total size of the array being sorted.
 */
void quickSort(int *arr, int low, int high, int size)
{
	int pi;

	if (high > low)
	{
		pi = partition(arr, low, high, size);
		if (pi > low)
			quickSort(arr, low, pi, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Recursive quicksort using hoare partitions.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quickSort(array, 0, size - 1, size);
}
