#include "sort.h"

/**
 * swap - Swaps two emements of an integer array.
 *
 * @a: The array of integers.
 * @i1: The first element index.
 * @i2: The second element index.
 * @size: The size of the array.
 */
void swap(int *a, size_t i1, size_t i2, size_t size)
{
	a[i1] ^= a[i2];
	a[i2] ^= a[i1];
	a[i1] ^= a[i2];

	print_array(a, size);
}

/**
 * partition - Partitions an array and returns a pivot index.
 *
 * @a: Array to be partitioned.
 * @lo: Lower bound of array to be sorted.
 * @hi: Upper index of array to be sorted.
 * @size: Size of the array to be sorted.
 *
 * Return: Pivot index.
 */
size_t partition(int *a, size_t lo, size_t hi, size_t size)
{
	size_t i, j;
	int pivot_digit;

	/* Choosing the last digit as pivot. */
	pivot_digit = a[hi];
	/* Temporary pivot index. */
	i = lo;

	for (j = lo; j < hi; j++)
		/* If the current element is less than or equal to the pivot. */
		if (a[j] < pivot_digit)
		{
			/* Swap the current element with the element at the temporary index */
			if (i != j)
				swap(a, i, j, size);
			/* Move the temporary pivot index forward. */
			i++;
		}

	/* Move the pivot element to the correct pivot position (btn sml and lrg)*/
	if (a[hi] < a[i])
		swap(a, i, hi, size);
	return (i);
}

/**
 * quickSort - The recursive module of the quick sort algorithm.
 *
 * @a: The array to be sorted.
 * @lo: The lower bounds of the array.
 * @hi: The upper bound of the array to be sorted.
 * @size: The size of the array.
 */
void quickSort(int *a, size_t lo, size_t hi, size_t size)
{
	size_t pivot;

	/* Ensuring the indices are in correct order. */
	if (lo >= hi || hi >= size)
		return;
	/* Finding the index at which to split the array. */
	pivot = partition(a, lo, hi, size);

	/* Sorting left of pivot */
	quickSort(a, lo, pivot - 1, size);
	/* Sorting right of pivot */
	quickSort(a, pivot + 1, hi, size);
}

/**
 * quick_sort - Uses quick sort algorithm to sort an array of integers.
 *
 * @array: Array of integers.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	/* Checking if array is NULL or empty or a single item array */
	if (!array || size <= 1)
		return;
	/* Calling the recursive bit of quicksort. */
	quickSort(array, 0, size - 1, size);
}
